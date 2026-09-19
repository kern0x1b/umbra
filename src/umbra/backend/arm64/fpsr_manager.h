/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <mcl/stdint.hpp>

namespace oaknut {
struct CodeGenerator;
struct WReg;
}  // namespace oaknut

namespace Umbra::Backend::Arm64 {

class FpsrManager {
public:
    explicit FpsrManager(oaknut::CodeGenerator& code, size_t state_fpsr_offset);

    void Spill();
    void Load();
    void Overwrite() { fpsr_loaded = false; }

    void GetFpsr(oaknut::WReg);

private:
    oaknut::CodeGenerator& code;
    size_t state_fpsr_offset;
    bool fpsr_loaded = false;
};

}  // namespace Umbra::Backend::Arm64
