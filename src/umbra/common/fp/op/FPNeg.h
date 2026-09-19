/* SPDX-License-Identifier: 0BSD */

#pragma once

#include "umbra/common/fp/info.h"

namespace Umbra::FP {

template<typename FPT>
constexpr FPT FPNeg(FPT op) {
    return op ^ FPInfo<FPT>::sign_mask;
}

}  // namespace Umbra::FP
