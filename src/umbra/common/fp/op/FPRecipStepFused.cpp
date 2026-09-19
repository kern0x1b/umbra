/* SPDX-License-Identifier: 0BSD */

#include "umbra/common/fp/op/FPRecipStepFused.h"

#include "umbra/common/fp/fpcr.h"
#include "umbra/common/fp/fpsr.h"
#include "umbra/common/fp/fused.h"
#include "umbra/common/fp/info.h"
#include "umbra/common/fp/op/FPNeg.h"
#include "umbra/common/fp/process_nan.h"
#include "umbra/common/fp/unpacked.h"

namespace Umbra::FP {

template<typename FPT>
FPT FPRecipStepFused(FPT op1, FPT op2, FPCR fpcr, FPSR& fpsr) {
    op1 = FPNeg(op1);

    const auto [type1, sign1, value1] = FPUnpack<FPT>(op1, fpcr, fpsr);
    const auto [type2, sign2, value2] = FPUnpack<FPT>(op2, fpcr, fpsr);

    if (const auto maybe_nan = FPProcessNaNs(type1, type2, op1, op2, fpcr, fpsr)) {
        return *maybe_nan;
    }

    const bool inf1 = type1 == FPType::Infinity;
    const bool inf2 = type2 == FPType::Infinity;
    const bool zero1 = type1 == FPType::Zero;
    const bool zero2 = type2 == FPType::Zero;

    if ((inf1 && zero2) || (zero1 && inf2)) {
        // return +2.0
        return FPValue<FPT, false, 0, 2>();
    }

    if (inf1 || inf2) {
        return FPInfo<FPT>::Infinity(sign1 != sign2);
    }

    // result_value = 2.0 + (value1 * value2)
    const FPUnpacked result_value = FusedMulAdd(ToNormalized(false, 0, 2), value1, value2);

    if (result_value.mantissa == 0) {
        return FPInfo<FPT>::Zero(fpcr.RMode() == RoundingMode::TowardsMinusInfinity);
    }
    return FPRound<FPT>(result_value, fpcr, fpsr);
}

template u16 FPRecipStepFused<u16>(u16 op1, u16 op2, FPCR fpcr, FPSR& fpsr);
template u32 FPRecipStepFused<u32>(u32 op1, u32 op2, FPCR fpcr, FPSR& fpsr);
template u64 FPRecipStepFused<u64>(u64 op1, u64 op2, FPCR fpcr, FPSR& fpsr);

}  // namespace Umbra::FP
