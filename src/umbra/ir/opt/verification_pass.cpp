/* SPDX-License-Identifier: 0BSD */

#include <cstdio>
#include <map>

#include <mcl/assert.hpp>
#include <mcl/stdint.hpp>

#include "umbra/ir/basic_block.h"
#include "umbra/ir/microinstruction.h"
#include "umbra/ir/opcodes.h"
#include "umbra/ir/opt/passes.h"
#include "umbra/ir/type.h"

namespace Umbra::Optimization {

void VerificationPass(const IR::Block& block) {
    for (const auto& inst : block) {
        for (size_t i = 0; i < inst.NumArgs(); i++) {
            const IR::Type t1 = inst.GetArg(i).GetType();
            const IR::Type t2 = IR::GetArgTypeOf(inst.GetOpcode(), i);
            if (!IR::AreTypesCompatible(t1, t2)) {
                std::puts(IR::DumpBlock(block).c_str());
                ASSERT_FALSE("above block failed validation");
            }
        }
    }

    std::map<IR::Inst*, size_t> actual_uses;
    for (const auto& inst : block) {
        for (size_t i = 0; i < inst.NumArgs(); i++) {
            const auto arg = inst.GetArg(i);
            if (!arg.IsImmediate()) {
                actual_uses[arg.GetInst()]++;
            }
        }
    }

    for (const auto& pair : actual_uses) {
        ASSERT(pair.first->UseCount() == pair.second);
    }
}

}  // namespace Umbra::Optimization
