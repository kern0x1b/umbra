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
void EmitIR<IR::Opcode::CRC32Castagnoli8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::CRC32Castagnoli16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::CRC32Castagnoli32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::CRC32Castagnoli64>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::CRC32ISO8>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::CRC32ISO16>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::CRC32ISO32>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::CRC32ISO64>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::AESDecryptSingleRound>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::AESEncryptSingleRound>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::AESInverseMixColumns>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::AESMixColumns>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SM4AccessSubstitutionBox>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SHA256Hash>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SHA256MessageSchedule0>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::SHA256MessageSchedule1>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

}  // namespace Umbra::Backend::RV64
