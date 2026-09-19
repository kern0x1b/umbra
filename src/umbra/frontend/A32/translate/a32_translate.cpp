/* SPDX-License-Identifier: 0BSD */

#include "umbra/frontend/A32/translate/a32_translate.h"

#include "umbra/frontend/A32/a32_location_descriptor.h"
#include "umbra/ir/basic_block.h"

namespace Umbra::A32 {

IR::Block TranslateArm(LocationDescriptor descriptor, TranslateCallbacks* tcb, const TranslationOptions& options);
IR::Block TranslateThumb(LocationDescriptor descriptor, TranslateCallbacks* tcb, const TranslationOptions& options);

IR::Block Translate(LocationDescriptor descriptor, TranslateCallbacks* tcb, const TranslationOptions& options) {
    return (descriptor.TFlag() ? TranslateThumb : TranslateArm)(descriptor, tcb, options);
}

bool TranslateSingleArmInstruction(IR::Block& block, LocationDescriptor descriptor, u32 instruction);
bool TranslateSingleThumbInstruction(IR::Block& block, LocationDescriptor descriptor, u32 instruction);

bool TranslateSingleInstruction(IR::Block& block, LocationDescriptor descriptor, u32 instruction) {
    return (descriptor.TFlag() ? TranslateSingleThumbInstruction : TranslateSingleArmInstruction)(block, descriptor, instruction);
}

}  // namespace Umbra::A32
