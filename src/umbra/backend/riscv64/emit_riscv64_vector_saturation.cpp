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
void EmitIR<IR::Opcode::VectorSignedSaturatedAdd8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorSignedSaturatedAdd16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorSignedSaturatedAdd32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorSignedSaturatedAdd64>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorSignedSaturatedSub8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorSignedSaturatedSub16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorSignedSaturatedSub32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorSignedSaturatedSub64>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorUnsignedSaturatedAdd8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorUnsignedSaturatedAdd16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorUnsignedSaturatedAdd32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorUnsignedSaturatedAdd64>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorUnsignedSaturatedSub8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorUnsignedSaturatedSub16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorUnsignedSaturatedSub32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::VectorUnsignedSaturatedSub64>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

}  // namespace Umbra::Backend::RV64
