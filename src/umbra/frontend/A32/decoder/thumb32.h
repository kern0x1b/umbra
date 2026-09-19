/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <algorithm>
#include <optional>
#include <vector>

#include <mcl/stdint.hpp>

#include "umbra/frontend/decoder/decoder_detail.h"
#include "umbra/frontend/decoder/matcher.h"

namespace Umbra::A32 {

template<typename Visitor>
using Thumb32Matcher = Decoder::Matcher<Visitor, u32>;

template<typename V>
std::optional<std::reference_wrapper<const Thumb32Matcher<V>>> DecodeThumb32(u32 instruction) {
    static const std::vector<Thumb32Matcher<V>> table = {

#define INST(fn, name, bitstring) UMBRA_DECODER_GET_MATCHER(Thumb32Matcher, fn, name, Decoder::detail::StringToArray<32>(bitstring)),
#include "./thumb32.inc"
#undef INST

    };

    const auto matches_instruction = [instruction](const auto& matcher) { return matcher.Matches(instruction); };

    auto iter = std::find_if(table.begin(), table.end(), matches_instruction);
    return iter != table.end() ? std::optional<std::reference_wrapper<const Thumb32Matcher<V>>>(*iter) : std::nullopt;
}

}  // namespace Umbra::A32
