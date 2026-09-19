/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <cstddef>
#include <tuple>

#include <mcl/hash/xmrx.hpp>
#include <mcl/stdint.hpp>
#include <tsl/robin_set.h>

#include "umbra/backend/exception_handler.h"
#include "umbra/ir/location_descriptor.h"

namespace Umbra::Backend::Arm64 {

using DoNotFastmemMarker = std::tuple<IR::LocationDescriptor, unsigned>;

struct DoNotFastmemMarkerHash {
    size_t operator()(const DoNotFastmemMarker& value) const {
        return mcl::hash::xmrx(std::get<0>(value).Value() ^ static_cast<u64>(std::get<1>(value)));
    }
};

struct FastmemPatchInfo {
    DoNotFastmemMarker marker;
    FakeCall fc;
    bool recompile;
};

class FastmemManager {
public:
    explicit FastmemManager(ExceptionHandler& eh)
            : exception_handler(eh) {}

    bool SupportsFastmem() const {
        return exception_handler.SupportsFastmem();
    }

    bool ShouldFastmem(DoNotFastmemMarker marker) const {
        return do_not_fastmem.count(marker) == 0;
    }

    void MarkDoNotFastmem(DoNotFastmemMarker marker) {
        do_not_fastmem.insert(marker);
    }

private:
    ExceptionHandler& exception_handler;
    tsl::robin_set<DoNotFastmemMarker, DoNotFastmemMarkerHash> do_not_fastmem;
};

}  // namespace Umbra::Backend::Arm64
