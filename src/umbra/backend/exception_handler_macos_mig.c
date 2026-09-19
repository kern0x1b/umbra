/* SPDX-License-Identifier: 0BSD */

#include <mcl/macro/architecture.hpp>

#if defined(MCL_ARCHITECTURE_X86_64)
#    include "umbra/backend/x64/mig/mach_exc_server.c"
#elif defined(MCL_ARCHITECTURE_ARM64)
#    include "umbra/backend/arm64/mig/mach_exc_server.c"
#else
#    error "Invalid architecture"
#endif
