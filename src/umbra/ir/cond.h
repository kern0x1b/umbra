/* SPDX-License-Identifier: 0BSD */

#pragma once

namespace Umbra::IR {

enum class Cond {
    EQ,
    NE,
    CS,
    CC,
    MI,
    PL,
    VS,
    VC,
    HI,
    LS,
    GE,
    LT,
    GT,
    LE,
    AL,
    NV,
    HS = CS,
    LO = CC,
};

}  // namespace Umbra::IR
