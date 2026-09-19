/* SPDX-License-Identifier: 0BSD */

#include <mcl/macro/architecture.hpp>

#if defined(MCL_ARCHITECTURE_X86_64)
#    include "umbra/backend/x64/exception_handler_windows.cpp"
#elif defined(MCL_ARCHITECTURE_ARM64)
#    include "umbra/backend/exception_handler_generic.cpp"
#else
#    error "Invalid architecture"
#endif
