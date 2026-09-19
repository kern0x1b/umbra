/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <string_view>

#include <mcl/bit_cast.hpp>

namespace Umbra::Backend::X64 {

// Check before constructing per-block names when optional perf output is off.
bool PerfMapEnabled();

namespace detail {
void PerfMapRegister(const void* start, const void* end, std::string_view friendly_name);
}  // namespace detail

template<typename T>
void PerfMapRegister(T start, const void* end, std::string_view friendly_name) {
    detail::PerfMapRegister(mcl::bit_cast<const void*>(start), end, friendly_name);
}

void PerfMapClear();

}  // namespace Umbra::Backend::X64
