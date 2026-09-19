/* SPDX-License-Identifier: 0BSD */

#include "umbra/ir/basic_block.h"
#include "umbra/ir/microinstruction.h"

namespace Umbra::Optimization {

void NamingPass(IR::Block& block) {
    unsigned name = 1;
    for (auto& inst : block) {
        inst.SetName(name++);
    }
}

}  // namespace Umbra::Optimization
