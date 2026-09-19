/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <mcl/stdint.hpp>

namespace Umbra::IR {
enum class Cond;
}  // namespace Umbra::IR

namespace Umbra::A32 {

class IREmitter;
struct TranslatorVisitor;

enum class ConditionalState {
    /// We haven't met any conditional instructions yet.
    None,
    /// Current instruction is a conditional. This marks the end of this basic block.
    Break,
    /// This basic block is made up solely of conditional instructions.
    Translating,
    /// This basic block is made up of conditional instructions followed by unconditional instructions.
    Trailing,
};

bool CondCanContinue(ConditionalState cond_state, const A32::IREmitter& ir);
bool IsConditionPassed(TranslatorVisitor& v, IR::Cond cond);

}  // namespace Umbra::A32
