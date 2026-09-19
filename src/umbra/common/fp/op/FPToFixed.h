/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <mcl/stdint.hpp>

namespace Umbra::FP {

class FPCR;
class FPSR;
enum class RoundingMode;

template<typename FPT>
u64 FPToFixed(size_t ibits, FPT op, size_t fbits, bool unsigned_, FPCR fpcr, RoundingMode rounding, FPSR& fpsr);

}  // namespace Umbra::FP
