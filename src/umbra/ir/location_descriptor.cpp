/* SPDX-License-Identifier: 0BSD */

#include "umbra/ir/location_descriptor.h"

#include <fmt/format.h>

namespace Umbra::IR {

std::string ToString(const LocationDescriptor& descriptor) {
    return fmt::format("{{{:016x}}}", descriptor.Value());
}

}  // namespace Umbra::IR
