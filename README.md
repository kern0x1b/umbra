# Umbra

**The ARM JIT core under Shade: a dynamic recompiler that runs 32-bit ARM guest code on an arm64 host.**

Umbra translates guest ARM code to host machine code as it runs. It is the CPU
of [Shade](https://github.com/kern0x1b/shade), Charon's emulator for legacy
iPhone OS and iOS userlands, and it can be used on its own by any program that
brings its own memory system.

## What it does

- Fast dynamic binary translation of guest ARM code, through an intermediate
  representation, into host code.
- Guest architectures ARMv3 to 64-bit v8; the ARMv6 and ARMv7 cores are the ones
  Shade exercises.
- Host back ends for AArch64 and x86-64, and a RISC-V 64 one in the tree.
  **Tested here on macOS arm64 only.**
- A public API for memory access, supervisor calls, exceptions, tick counting,
  code invalidation and per-block instrumentation hooks; the guest's address
  space is entirely the caller's.

What it leaves out on purpose is described in the
[guide](docs/guide.md#disadvantages-of-umbra): user mode only, approximate
floating-point status, and a guest can tell it is being translated.

## Requirements

- CMake 3.24 or later and a C++20 compiler (Apple clang on macOS).
- Boost headers, version 1.71.0 is what it is built and tested against; the
  trimmed subset at [shade-boost](https://github.com/kern0x1b/shade-boost) is
  enough.
- The libraries under `externals/` are in the tree.

## Build

```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DUMBRA_TESTS=ON \
      -DBoost_INCLUDE_DIR=/path/to/boost -DBoost_NO_SYSTEM_PATHS=ON \
      -DCMAKE_CXX_FLAGS=-D_LIBCPP_ENABLE_CXX17_REMOVED_UNARY_BINARY_FUNCTION
cmake --build build
```

The compiler flag is needed with Boost 1.71.0 and a current Apple libc++, which
removed `std::unary_function`.

## Usage

The [guide](docs/guide.md) has a minimal, complete example: a guest whose memory
is a byte array. Run the tests with:

```sh
./build/tests/umbra_tests           # all of them
./build/tests/umbra_tests "[A32]"   # one group
```

## Repository layout

| Path | Holds |
| --- | --- |
| `src/umbra/` | the library: `frontend/` decoders, `ir/`, `backend/` per host, `interface/` the public API |
| `tests/` | the test suites, `A32/` and `A64/` run guest code |
| `docs/` | the guide and the design notes |
| `externals/` | the libraries it builds against, each with its own license |

## Documentation

| Document | About |
| --- | --- |
| [docs/guide.md](docs/guide.md) | features, supported architectures, an example, limitations |
| [docs/Design.md](docs/Design.md) | how translation works |
| [docs/RegisterAllocator.md](docs/RegisterAllocator.md) | register allocation |
| [docs/ReturnStackBufferOptimization.md](docs/ReturnStackBufferOptimization.md) | the return stack buffer |
| [CLAUDE.md](CLAUDE.md) | the contributor guide |

## License

0BSD, see `LICENSE`. The libraries under `externals/` keep their own licenses;
they are listed in `THIRD-PARTY.md`.

Built with Claude (Anthropic). This project is developed with AI assistance,
openly — see the commit history.
