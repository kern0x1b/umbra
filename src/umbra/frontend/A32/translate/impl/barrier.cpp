/* SPDX-License-Identifier: 0BSD */

#include "umbra/frontend/A32/translate/impl/a32_translate_impl.h"

namespace Umbra::A32 {

bool TranslatorVisitor::arm_DMB(Imm<4> /*option*/) {
    ir.DataMemoryBarrier();
    return true;
}

bool TranslatorVisitor::arm_DSB(Imm<4> /*option*/) {
    ir.DataSynchronizationBarrier();
    return true;
}

bool TranslatorVisitor::arm_ISB(Imm<4> /*option*/) {
    ir.InstructionSynchronizationBarrier();
    ir.BranchWritePC(ir.Imm32(ir.current_location.PC() + 4));
    ir.SetTerm(IR::Term::ReturnToDispatch{});
    return false;
}

}  // namespace Umbra::A32
