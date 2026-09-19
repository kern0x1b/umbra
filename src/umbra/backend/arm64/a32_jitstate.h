/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <array>
#include <atomic>

#include <mcl/stdint.hpp>

#include "umbra/frontend/A32/a32_location_descriptor.h"
#include "umbra/ir/location_descriptor.h"

namespace Umbra::Backend::Arm64 {

struct A32JitState {
    u32 cpsr_nzcv = 0;
    u32 cpsr_q = 0;
    u32 cpsr_jaifm = 0;
    u32 cpsr_ge = 0;

    u32 fpsr = 0;
    u32 fpsr_nzcv = 0;

    std::array<u32, 16> regs{};

    u32 upper_location_descriptor = 0;

    alignas(16) std::array<u32, 64> ext_regs{};

    u32 exclusive_state = 0;

    volatile u32 halt_reason = 0;

    u32 host_execution_block_budget = 0;
    u32 host_execution_block_budget_initial = 0;
    u32 host_execution_budget_exhausted = 0;

    const std::atomic<u64>* callbacks_link = nullptr;
    const std::atomic<u64>* lookup_link = nullptr;
    const std::atomic<u64>* runtime_config_link = nullptr;
    const std::atomic<u64>* page_table_link = nullptr;
    const std::atomic<u64>* read_page_table_link = nullptr;
    const std::atomic<u64>* coprocessor_user_arg_link = nullptr;

    u64 rsb_hits = 0;
    u64 rsb_misses = 0;

    u32 Cpsr() const;
    void SetCpsr(u32 cpsr);

    u32 Fpscr() const;
    void SetFpscr(u32 fpscr);

    IR::LocationDescriptor GetLocationDescriptor() const {
        return IR::LocationDescriptor{regs[15] | (static_cast<u64>(upper_location_descriptor) << 32)};
    }
};

}  // namespace Umbra::Backend::Arm64
