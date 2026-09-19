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
void EmitIR<IR::Opcode::A32CoprocInternalOperation>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::A32CoprocSendOneWord>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::A32CoprocSendTwoWords>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::A32CoprocGetOneWord>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::A32CoprocGetTwoWords>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::A32CoprocLoadWords>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

template<>
void EmitIR<IR::Opcode::A32CoprocStoreWords>(biscuit::Assembler&, EmitContext&, IR::Inst*) {
    UNIMPLEMENTED();
}

}  // namespace Umbra::Backend::RV64
