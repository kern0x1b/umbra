/* SPDX-License-Identifier: 0BSD */

#pragma once

namespace Umbra::FP {

class FPCR;
class FPSR;

template<typename FPT>
bool FPCompareEQ(FPT lhs, FPT rhs, FPCR fpcr, FPSR& fpsr);

}  // namespace Umbra::FP
