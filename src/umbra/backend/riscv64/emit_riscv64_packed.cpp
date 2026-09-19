/* SPDX-License-Identifier: 0BSD */

#include <biscuit/assembler.hpp>
#include <fmt/ostream.h>

#include "umbra/backend/riscv64/a32_jitstate.h"
#include "umbra/backend/riscv64/abi.h"
#include "umbra/backend/riscv64/emit_context.h"
#include "umbra/backend/riscv64/emit_riscv64.h"
#include "umbra/backend/riscv64/reg_alloc.h"
#include "umbra/ir/basic_block.h"
#include "umbra/ir/microinstruction.h"
#include "umbra/ir/opcodes.h"

namespace Umbra::Backend::RV64 {

template<>
void EmitIR<IR::Opcode::PackedAddU8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedAddS8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSubU8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSubS8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedAddU16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedAddS16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSubU16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSubS16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedAddSubU16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedAddSubS16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSubAddU16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSubAddS16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingAddU8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingAddS8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingSubU8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingSubS8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingAddU16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingAddS16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingSubU16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingSubS16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingAddSubU16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingAddSubS16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingSubAddU16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedHalvingSubAddS16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSaturatedAddU8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSaturatedAddS8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSaturatedSubU8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSaturatedSubS8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSaturatedAddU16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSaturatedAddS16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSaturatedSubU16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSaturatedSubS16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedAbsDiffSumU8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::PackedSelect>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

}  // namespace Umbra::Backend::RV64
