/* SPDX-License-Identifier: 0BSD */

#include "umbra/frontend/A64/translate/impl/impl.h"

namespace Umbra::A64 {

bool TranslatorVisitor::FCSEL_float(Imm<2> type, Vec Vm, Cond cond, Vec Vn, Vec Vd) {
    const auto datasize = FPGetDataSize(type);
    if (!datasize || *datasize == 16) {
        return UnallocatedEncoding();
    }

    const IR::U32U64 operand1 = V_scalar(*datasize, Vn);
    const IR::U32U64 operand2 = V_scalar(*datasize, Vm);
    const IR::U32U64 result = ir.ConditionalSelect(cond, operand1, operand2);
    V_scalar(*datasize, Vd, result);

    return true;
}

}  // namespace Umbra::A64
