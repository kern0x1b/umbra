/* SPDX-License-Identifier: 0BSD */

#pragma once

#include "umbra/backend/riscv64/emit_riscv64.h"
#include "umbra/backend/riscv64/reg_alloc.h"

namespace Umbra::IR {
class Block;
}  // namespace Umbra::IR

namespace Umbra::Backend::RV64 {

struct EmitConfig;

struct EmitContext {
    IR::Block& block;
    RegAlloc& reg_alloc;
    const EmitConfig& emit_conf;
    EmittedBlockInfo& ebi;
};

}  // namespace Umbra::Backend::RV64
