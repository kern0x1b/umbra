/* SPDX-License-Identifier: 0BSD */

#include "umbra/frontend/A64/a64_location_descriptor.h"

#include <fmt/format.h>

namespace Umbra::A64 {

std::string ToString(const LocationDescriptor& descriptor) {
    return fmt::format("{{{}, {}{}}}", descriptor.PC(), descriptor.FPCR().Value(), descriptor.SingleStepping() ? ", step" : "");
}

}  // namespace Umbra::A64
