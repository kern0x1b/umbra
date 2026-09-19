/* SPDX-License-Identifier: 0BSD */

#pragma once

namespace Umbra {

struct SpinLock {
    void Lock();
    void Unlock();

    volatile int storage = 0;
};

}  // namespace Umbra
