/* SPDX-License-Identifier: 0BSD */

#include <mutex>

#include <xbyak/xbyak.h>

#include "umbra/backend/x64/abi.h"
#include "umbra/backend/x64/hostloc.h"
#include "umbra/common/spin_lock.h"

namespace Umbra {

void EmitSpinLockLock(Xbyak::CodeGenerator& code, Xbyak::Reg64 ptr, Xbyak::Reg32 tmp) {
    Xbyak::Label start, loop;

    code.jmp(start);
    code.L(loop);
    code.pause();
    code.L(start);
    code.mov(tmp, 1);
    code.lock();
    code.xchg(code.dword[ptr], tmp);
    code.test(tmp, tmp);
    code.jnz(loop);
}

void EmitSpinLockUnlock(Xbyak::CodeGenerator& code, Xbyak::Reg64 ptr, Xbyak::Reg32 tmp) {
    code.xor_(tmp, tmp);
    code.xchg(code.dword[ptr], tmp);
    code.mfence();
}

namespace {

struct SpinLockImpl {
    void Initialize();

    Xbyak::CodeGenerator code;

    void (*lock)(volatile int*);
    void (*unlock)(volatile int*);
};

std::once_flag flag;
SpinLockImpl impl;

void SpinLockImpl::Initialize() {
    const Xbyak::Reg64 ABI_PARAM1 = Backend::X64::HostLocToReg64(Backend::X64::ABI_PARAM1);

    code.align();
    lock = code.getCurr<void (*)(volatile int*)>();
    EmitSpinLockLock(code, ABI_PARAM1, code.eax);
    code.ret();

    code.align();
    unlock = code.getCurr<void (*)(volatile int*)>();
    EmitSpinLockUnlock(code, ABI_PARAM1, code.eax);
    code.ret();
}

}  // namespace

void SpinLock::Lock() {
    std::call_once(flag, &SpinLockImpl::Initialize, impl);
    impl.lock(&storage);
}

void SpinLock::Unlock() {
    std::call_once(flag, &SpinLockImpl::Initialize, impl);
    impl.unlock(&storage);
}

}  // namespace Umbra
