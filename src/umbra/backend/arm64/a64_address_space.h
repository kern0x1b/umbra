/* SPDX-License-Identifier: 0BSD */

#pragma once

#include "umbra/backend/arm64/address_space.h"
#include "umbra/backend/block_range_information.h"
#include "umbra/interface/A64/config.h"

namespace Umbra::Backend::Arm64 {

struct EmittedBlockInfo;

class A64AddressSpace final : public AddressSpace {
public:
    explicit A64AddressSpace(const A64::UserConfig& conf);

    IR::Block GenerateIR(IR::LocationDescriptor) const override;

    void InvalidateCacheRanges(const boost::icl::interval_set<u64>& ranges);

protected:
    friend class A64Core;

    void EmitPrelude();
    EmitConfig GetEmitConfig() override;
    void RegisterNewBasicBlock(const IR::Block& block, const EmittedBlockInfo& block_info) override;

    const A64::UserConfig conf;
    BlockRangeInformation<u64> block_ranges;
};

}  // namespace Umbra::Backend::Arm64
