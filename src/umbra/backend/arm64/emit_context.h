/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <functional>
#include <memory>
#include <vector>

#include <oaknut/oaknut.hpp>

#include "umbra/backend/arm64/emit_arm64.h"
#include "umbra/backend/arm64/reg_alloc.h"
#include "umbra/common/fp/fpcr.h"
#include "umbra/ir/basic_block.h"

namespace Umbra::IR {
class Block;
}  // namespace Umbra::IR

namespace Umbra::Backend::Arm64 {

struct EmitConfig;
class FastmemManager;
class FpsrManager;

using SharedLabel = std::shared_ptr<oaknut::Label>;

inline SharedLabel GenSharedLabel() {
    return std::make_shared<oaknut::Label>();
}

struct EmitContext {
    IR::Block& block;
    RegAlloc& reg_alloc;
    const EmitConfig& conf;
    EmittedBlockInfo& ebi;
    FpsrManager& fpsr;
    FastmemManager& fastmem;

    std::vector<std::function<void()>> deferred_emits;

    FP::FPCR FPCR(bool fpcr_controlled = true) const {
        const FP::FPCR fpcr = conf.descriptor_to_fpcr(block.Location());
        return fpcr_controlled ? fpcr : fpcr.ASIMDStandardValue();
    }
};

}  // namespace Umbra::Backend::Arm64
