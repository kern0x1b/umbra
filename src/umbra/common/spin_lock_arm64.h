/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <oaknut/oaknut.hpp>

namespace Umbra {

void EmitSpinLockLock(oaknut::CodeGenerator& code, oaknut::XReg ptr);
void EmitSpinLockUnlock(oaknut::CodeGenerator& code, oaknut::XReg ptr);

}  // namespace Umbra
