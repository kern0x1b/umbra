/* SPDX-License-Identifier: 0BSD */

#include "umbra/backend/x64/block_of_code.h"
#include "umbra/backend/x64/emit_x64.h"
#include "umbra/common/crypto/sm4.h"
#include "umbra/ir/microinstruction.h"

namespace Umbra::Backend::X64 {

void EmitX64::EmitSM4AccessSubstitutionBox(EmitContext& ctx, IR::Inst* inst) {
    auto args = ctx.reg_alloc.GetArgumentInfo(inst);

    ctx.reg_alloc.HostCall(inst, args[0]);
    code.CallFunction(&Common::Crypto::SM4::AccessSubstitutionBox);
    code.movzx(code.ABI_RETURN.cvt32(), code.ABI_RETURN.cvt8());
}

}  // namespace Umbra::Backend::X64
