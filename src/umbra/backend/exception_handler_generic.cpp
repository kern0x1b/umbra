/* SPDX-License-Identifier: 0BSD */

#include "umbra/backend/exception_handler.h"

namespace Umbra::Backend {

struct ExceptionHandler::Impl final {
};

ExceptionHandler::ExceptionHandler() = default;
ExceptionHandler::~ExceptionHandler() = default;

#if defined(MCL_ARCHITECTURE_X86_64)
void ExceptionHandler::Register(X64::BlockOfCode&) {
    // Do nothing
}
#elif defined(MCL_ARCHITECTURE_ARM64)
void ExceptionHandler::Register(oaknut::CodeBlock&, std::size_t) {
    // Do nothing
}
#elif defined(MCL_ARCHITECTURE_RISCV)
void ExceptionHandler::Register(RV64::CodeBlock&, std::size_t) {
    // Do nothing
}
#else
#    error "Invalid architecture"
#endif

bool ExceptionHandler::SupportsFastmem() const noexcept {
    return false;
}

void ExceptionHandler::SetFastmemCallback(std::function<FakeCall(u64)>) {
    // Do nothing
}

}  // namespace Umbra::Backend
