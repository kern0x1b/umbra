/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <string>

#include <mcl/stdint.hpp>

namespace Umbra::Common {

std::string DisassembleX64(const void* pos, const void* end);
std::string DisassembleAArch32(bool is_thumb, u32 pc, const u8* instructions, size_t length);
std::string DisassembleAArch64(u32 instruction, u64 pc = 0);

}  // namespace Umbra::Common
