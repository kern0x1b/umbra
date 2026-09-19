/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <mcl/stdint.hpp>

namespace Umbra::FP {

class FPCR;
class FPSR;
enum class RoundingMode;

template<typename FPT>
u64 FPRoundInt(FPT op, FPCR fpcr, RoundingMode rounding, bool exact, FPSR& fpsr);

}  // namespace Umbra::FP
