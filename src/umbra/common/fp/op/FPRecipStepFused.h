/* SPDX-License-Identifier: 0BSD */

#pragma once

namespace Umbra::FP {

class FPCR;
class FPSR;

template<typename FPT>
FPT FPRecipStepFused(FPT op1, FPT op2, FPCR fpcr, FPSR& fpsr);

}  // namespace Umbra::FP
