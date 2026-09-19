/* SPDX-License-Identifier: 0BSD */

#include "umbra/frontend/A64/translate/impl/impl.h"

namespace Umbra::A64 {

bool TranslatorVisitor::BRK(Imm<16> /*imm16*/) {
    return RaiseException(Exception::Breakpoint);
}

bool TranslatorVisitor::SVC(Imm<16> imm16) {
    ir.PushRSB(ir.current_location->AdvancePC(4));
    ir.SetPC(ir.Imm64(ir.current_location->PC() + 4));
    ir.CallSupervisor(imm16.ZeroExtend());
    ir.SetTerm(IR::Term::CheckHalt{IR::Term::PopRSBHint{}});
    return false;
}

}  // namespace Umbra::A64
