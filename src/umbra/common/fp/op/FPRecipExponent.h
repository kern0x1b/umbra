/* SPDX-License-Identifier: 0BSD */

#pragma once

namespace Umbra::FP {

class FPCR;
class FPSR;

template<typename FPT>
FPT FPRecipExponent(FPT op, FPCR fpcr, FPSR& fpsr);

}  // namespace Umbra::FP
