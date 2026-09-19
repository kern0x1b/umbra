/* SPDX-License-Identifier: 0BSD */

#include <mcl/assert.hpp>

#include "umbra/frontend/A32/a32_location_descriptor.h"
#include "umbra/frontend/A32/a32_types.h"
#include "umbra/frontend/A32/decoder/arm.h"
#include "umbra/frontend/A32/decoder/asimd.h"
#include "umbra/frontend/A32/decoder/vfp.h"
#include "umbra/frontend/A32/translate/a32_translate.h"
#include "umbra/frontend/A32/translate/conditional_state.h"
#include "umbra/frontend/A32/translate/impl/a32_translate_impl.h"
#include "umbra/frontend/A32/translate/translate_callbacks.h"
#include "umbra/interface/A32/config.h"
#include "umbra/ir/basic_block.h"

namespace Umbra::A32 {

IR::Block TranslateArm(LocationDescriptor descriptor, TranslateCallbacks* tcb, const TranslationOptions& options) {
    const bool single_step = descriptor.SingleStepping();

    IR::Block block{descriptor};
    TranslatorVisitor visitor{block, descriptor, options};

    bool should_continue = true;
    do {
        const u32 arm_pc = visitor.ir.current_location.PC();
        u64 ticks_for_instruction = 1;

        if (!tcb->PreCodeReadHook(false, arm_pc, visitor.ir)) {
            should_continue = false;
            break;
        }

        if (const auto arm_instruction = tcb->MemoryReadCode(arm_pc)) {
            visitor.current_instruction_size = 4;

            tcb->PreCodeTranslationHook(false, arm_pc, visitor.ir);
            ticks_for_instruction = tcb->GetTicksForCode(false, arm_pc, *arm_instruction);

            if (const auto vfp_decoder = DecodeVFP<TranslatorVisitor>(*arm_instruction)) {
                should_continue = vfp_decoder->get().call(visitor, *arm_instruction);
            } else if (const auto asimd_decoder = DecodeASIMD<TranslatorVisitor>(*arm_instruction)) {
                should_continue = asimd_decoder->get().call(visitor, *arm_instruction);
            } else if (const auto decoder = DecodeArm<TranslatorVisitor>(*arm_instruction)) {
                should_continue = decoder->get().call(visitor, *arm_instruction);
            } else {
                should_continue = visitor.arm_UDF();
            }
        } else {
            visitor.current_instruction_size = 4;

            should_continue = visitor.RaiseException(Exception::NoExecuteFault);
        }

        if (visitor.cond_state == ConditionalState::Break) {
            break;
        }

        visitor.ir.current_location = visitor.ir.current_location.AdvancePC(4);
        block.CycleCount() += ticks_for_instruction;
    } while (should_continue && CondCanContinue(visitor.cond_state, visitor.ir) && !single_step);

    if (visitor.cond_state == ConditionalState::Translating || visitor.cond_state == ConditionalState::Trailing || single_step) {
        if (should_continue) {
            if (single_step) {
                visitor.ir.SetTerm(IR::Term::LinkBlock{visitor.ir.current_location});
            } else {
                visitor.ir.SetTerm(IR::Term::LinkBlockFast{visitor.ir.current_location});
            }
        }
    }

    ASSERT_MSG(block.HasTerminal(), "Terminal has not been set");

    block.SetEndLocation(visitor.ir.current_location);

    return block;
}

bool TranslateSingleArmInstruction(IR::Block& block, LocationDescriptor descriptor, u32 arm_instruction) {
    TranslatorVisitor visitor{block, descriptor, {}};

    bool should_continue = true;

    // TODO: Proper cond handling

    visitor.current_instruction_size = 4;

    const u64 ticks_for_instruction = 1;

    if (const auto vfp_decoder = DecodeVFP<TranslatorVisitor>(arm_instruction)) {
        should_continue = vfp_decoder->get().call(visitor, arm_instruction);
    } else if (const auto asimd_decoder = DecodeASIMD<TranslatorVisitor>(arm_instruction)) {
        should_continue = asimd_decoder->get().call(visitor, arm_instruction);
    } else if (const auto decoder = DecodeArm<TranslatorVisitor>(arm_instruction)) {
        should_continue = decoder->get().call(visitor, arm_instruction);
    } else {
        should_continue = visitor.arm_UDF();
    }

    // TODO: Feedback resulting cond status to caller somehow.

    visitor.ir.current_location = visitor.ir.current_location.AdvancePC(4);
    block.CycleCount() += ticks_for_instruction;

    block.SetEndLocation(visitor.ir.current_location);

    return should_continue;
}

}  // namespace Umbra::A32
