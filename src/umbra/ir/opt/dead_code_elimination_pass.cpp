/* SPDX-License-Identifier: 0BSD */

#include <mcl/iterator/reverse.hpp>

#include "umbra/ir/basic_block.h"
#include "umbra/ir/opt/passes.h"

namespace Umbra::Optimization {

void DeadCodeElimination(IR::Block& block) {
    // We iterate over the instructions in reverse order.
    // This is because removing an instruction reduces the number of uses for earlier instructions.
    for (auto& inst : mcl::iterator::reverse(block)) {
        if (!inst.HasUses() && !inst.MayHaveSideEffects()) {
            inst.Invalidate();
        }
    }
}

}  // namespace Umbra::Optimization
