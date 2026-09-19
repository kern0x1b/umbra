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
void EmitIR<IR::Opcode::SignedSaturatedAddWithFlag32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturatedSubWithFlag32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturation>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::UnsignedSaturation>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturatedAdd8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturatedAdd16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturatedAdd32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturatedAdd64>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturatedDoublingMultiplyReturnHigh16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturatedDoublingMultiplyReturnHigh32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturatedSub8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturatedSub16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturatedSub32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SignedSaturatedSub64>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::UnsignedSaturatedAdd8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::UnsignedSaturatedAdd16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::UnsignedSaturatedAdd32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::UnsignedSaturatedAdd64>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::UnsignedSaturatedSub8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::UnsignedSaturatedSub16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::UnsignedSaturatedSub32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::UnsignedSaturatedSub64>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

}  // namespace Umbra::Backend::RV64
