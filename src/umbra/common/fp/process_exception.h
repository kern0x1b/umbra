/* SPDX-License-Identifier: 0BSD */

#pragma once

namespace Umbra::FP {

class FPCR;
class FPSR;

enum class FPExc {
    InvalidOp,
    DivideByZero,
    Overflow,
    Underflow,
    Inexact,
    InputDenorm,
};

void FPProcessException(FPExc exception, FPCR fpcr, FPSR& fpsr);

}  // namespace Umbra::FP
