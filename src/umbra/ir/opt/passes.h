/* SPDX-License-Identifier: 0BSD */

#pragma once

namespace Umbra::A32 {
struct UserCallbacks;
}

namespace Umbra::A64 {
struct UserCallbacks;
struct UserConfig;
}  // namespace Umbra::A64

namespace Umbra::IR {
class Block;
}

namespace Umbra::Optimization {

struct PolyfillOptions {
    bool sha256 = false;
    bool vector_multiply_widen = false;

    bool operator==(const PolyfillOptions&) const = default;
};

struct A32GetSetEliminationOptions {
    bool convert_nzc_to_nz = false;
    bool convert_nz_to_nzc = false;
    bool preserve_state_at_memory_access = false;
};

void PolyfillPass(IR::Block& block, const PolyfillOptions& opt);
void A32ConstantMemoryReads(IR::Block& block, A32::UserCallbacks* cb);
void A32GetSetElimination(IR::Block& block, A32GetSetEliminationOptions opt);
void A64CallbackConfigPass(IR::Block& block, const A64::UserConfig& conf);
void A64GetSetElimination(IR::Block& block);
void A64MergeInterpretBlocksPass(IR::Block& block, A64::UserCallbacks* cb);
void ConstantPropagation(IR::Block& block);
void DeadCodeElimination(IR::Block& block);
void IdentityRemovalPass(IR::Block& block);
void VerificationPass(const IR::Block& block);
void NamingPass(IR::Block& block);

}  // namespace Umbra::Optimization
