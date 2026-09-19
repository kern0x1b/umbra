/* SPDX-License-Identifier: 0BSD */

#include "umbra/frontend/A32/a32_location_descriptor.h"

#include <fmt/format.h>

namespace Umbra::A32 {

std::string ToString(const LocationDescriptor& descriptor) {
    return fmt::format("{{{:08x},{},{},{:08x}{}}}",
                       descriptor.PC(),
                       descriptor.TFlag() ? "T" : "!T",
                       descriptor.EFlag() ? "E" : "!E",
                       descriptor.FPSCR().Value(),
                       descriptor.SingleStepping() ? ",step" : "");
}

}  // namespace Umbra::A32
