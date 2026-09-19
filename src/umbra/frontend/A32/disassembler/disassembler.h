/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <string>

#include <mcl/stdint.hpp>

namespace Umbra::A32 {

std::string DisassembleArm(u32 instruction);
std::string DisassembleThumb16(u16 instruction);

}  // namespace Umbra::A32
