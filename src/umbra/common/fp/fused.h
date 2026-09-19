/* SPDX-License-Identifier: 0BSD */

#pragma once

namespace Umbra::FP {

struct FPUnpacked;

/// This function assumes all arguments have been normalized.
FPUnpacked FusedMulAdd(FPUnpacked addend, FPUnpacked op1, FPUnpacked op2);

}  // namespace Umbra::FP
