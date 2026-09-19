/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <xbyak/xbyak.h>

namespace Umbra {

void EmitSpinLockLock(Xbyak::CodeGenerator& code, Xbyak::Reg64 ptr, Xbyak::Reg32 tmp);
void EmitSpinLockUnlock(Xbyak::CodeGenerator& code, Xbyak::Reg64 ptr, Xbyak::Reg32 tmp);

}  // namespace Umbra
