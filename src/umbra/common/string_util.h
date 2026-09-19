/* SPDX-License-Identifier: 0BSD */

#pragma once

namespace Umbra::Common {

template<typename T>
constexpr char SignToChar(T value) {
    return value >= 0 ? '+' : '-';
}

}  // namespace Umbra::Common
