/* This file is part of the dynarmic project.
 * Copyright (c) 2022 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#pragma once

#include "dynarmic/backend/arm64/address_space.h"
#include "dynarmic/backend/block_range_information.h"
#include "dynarmic/interface/A32/config.h"

namespace Dynarmic::Backend::Arm64 {

struct EmittedBlockInfo;

class A32AddressSpace final : public AddressSpace {
public:
    using LookupBlockFunction = CodePtr (*)(void* lookup_arg);

    explicit A32AddressSpace(const A32::UserConfig& conf);
    A32AddressSpace(const A32::UserConfig& conf, LookupBlockFunction lookup, void* lookup_arg);

    IR::Block GenerateIR(IR::LocationDescriptor) const override;

    tsl::robin_set<IR::LocationDescriptor> InvalidateCacheRanges(const boost::icl::interval_set<u32>& ranges);

    void ClearCacheAndRanges();

    RetiredCodeStats RetireCodeRangeAndRanges(CodePtr begin, CodePtr end);

    typename BlockRangeInformation<u32>::Stats GetRangeStats() const noexcept { return block_ranges.GetStats(); }

    PreludeInfo::RunCodeFuncType RunCodeFunction() const { return prelude_info.run_code; }
    PreludeInfo::RunCodeFuncType StepCodeFunction() const { return prelude_info.step_code; }

protected:
    friend class A32Core;

    void EmitPrelude();
    EmitConfig GetEmitConfig() override;
    void RegisterNewBasicBlock(const IR::Block& block, const EmittedBlockInfo& block_info) override;

    bool ReadPageTableInRegister() const;

    const A32::UserConfig conf;
    LookupBlockFunction lookup_block = nullptr;
    void* lookup_block_arg = nullptr;
    BlockRangeInformation<u32> block_ranges;
};

}  // namespace Dynarmic::Backend::Arm64
