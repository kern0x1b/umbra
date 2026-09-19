/* SPDX-License-Identifier: 0BSD */

#include <mcl/stdint.hpp>

namespace oaknut {
struct CodeGenerator;
struct Label;
}  // namespace oaknut

namespace Umbra::IR {
enum class AccType;
class Inst;
}  // namespace Umbra::IR

namespace Umbra::Backend::Arm64 {

struct EmitContext;
enum class LinkTarget;

template<size_t bitsize>
void EmitReadMemory(oaknut::CodeGenerator& code, EmitContext& ctx, IR::Inst* inst);
template<size_t bitsize>
void EmitExclusiveReadMemory(oaknut::CodeGenerator& code, EmitContext& ctx, IR::Inst* inst);
template<size_t bitsize>
void EmitWriteMemory(oaknut::CodeGenerator& code, EmitContext& ctx, IR::Inst* inst);
template<size_t bitsize>
void EmitSwapMemory(oaknut::CodeGenerator& code, EmitContext& ctx, IR::Inst* inst);
template<size_t bitsize>
void EmitExclusiveWriteMemory(oaknut::CodeGenerator& code, EmitContext& ctx, IR::Inst* inst);

}  // namespace Umbra::Backend::Arm64
