/* SPDX-License-Identifier: 0BSD */

#pragma once

namespace Umbra::IR {

enum class AccType {
    NORMAL,
    VEC,
    STREAM,
    VECSTREAM,
    ATOMIC,
    ORDERED,
    ORDEREDRW,
    LIMITEDORDERED,
    UNPRIV,
    IFETCH,
    PTW,
    DC,
    IC,
    DCZVA,
    AT,
    SWAP,  // TODO: Remove
};

}  // namespace Umbra::IR
