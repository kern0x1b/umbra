/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <cstdint>
#include <string>

namespace Umbra {
namespace A32 {

std::string DisassembleArm(std::uint32_t instruction);
std::string DisassembleThumb16(std::uint16_t instruction);

}  // namespace A32
}  // namespace Umbra
