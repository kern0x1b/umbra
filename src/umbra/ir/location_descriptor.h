/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <functional>
#include <string>

#include <fmt/format.h>
#include <mcl/stdint.hpp>

namespace Umbra::IR {

class LocationDescriptor {
public:
    explicit LocationDescriptor(u64 value)
            : value(value) {}

    bool operator==(const LocationDescriptor& o) const {
        return value == o.Value();
    }

    bool operator!=(const LocationDescriptor& o) const {
        return !operator==(o);
    }

    u64 Value() const { return value; }

private:
    u64 value;
};

std::string ToString(const LocationDescriptor& descriptor);

inline bool operator<(const LocationDescriptor& x, const LocationDescriptor& y) noexcept {
    return x.Value() < y.Value();
}

}  // namespace Umbra::IR

namespace std {
template<>
struct less<Umbra::IR::LocationDescriptor> {
    bool operator()(const Umbra::IR::LocationDescriptor& x, const Umbra::IR::LocationDescriptor& y) const noexcept {
        return x < y;
    }
};
template<>
struct hash<Umbra::IR::LocationDescriptor> {
    size_t operator()(const Umbra::IR::LocationDescriptor& x) const noexcept {
        return std::hash<u64>()(x.Value());
    }
};
}  // namespace std

template<>
struct fmt::formatter<Umbra::IR::LocationDescriptor> : fmt::formatter<std::string> {
    template<typename FormatContext>
    auto format(Umbra::IR::LocationDescriptor descriptor, FormatContext& ctx) const {
        return formatter<std::string>::format(ToString(descriptor), ctx);
    }
};
