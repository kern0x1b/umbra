/* SPDX-License-Identifier: 0BSD */

#pragma once

#include <array>

#include <mcl/stdint.hpp>

namespace Umbra::Common::Crypto::AES {

using State = std::array<u8, 16>;

// Assumes the state has already been XORed by the round key.
void DecryptSingleRound(State& out_state, const State& state);
void EncryptSingleRound(State& out_state, const State& state);

void MixColumns(State& out_state, const State& state);
void InverseMixColumns(State& out_state, const State& state);

}  // namespace Umbra::Common::Crypto::AES
