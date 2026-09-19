/* SPDX-License-Identifier: 0BSD */

#pragma once

namespace Umbra::FP {

class FPCR;
class FPSR;
enum class RoundingMode;

template<typename FPT_TO, typename FPT_FROM>
FPT_TO FPConvert(FPT_FROM op, FPCR fpcr, RoundingMode rounding_mode, FPSR& fpsr);

}  // namespace Umbra::FP
