# Contributor guide

Working notes for whoever is changing Umbra, human or AI.

## What this is

A dynamic recompiler for guest ARM code. The public API is
`src/umbra/interface/`: `A32::Jit` and `A64::Jit` run guest code and call back
into a `UserCallbacks` the embedding program implements (memory, supervisor calls,
exceptions, ticks). The embedder here is Shade.

## Build and test

See the README for the configure line. The test target is `umbra_tests`, and the
suite is 122 test cases: `[A32]` and `[a64]` run guest code, the rest test the
decoders and floating-point helpers. Run all of it before a change and after.
`UMBRA_TESTS_USE_UNICORN` adds fuzzing against Unicorn and is off by default.

## Layout

- `src/umbra/frontend/` decodes guest instructions into IR.
- `src/umbra/ir/` is the intermediate representation and its passes.
- `src/umbra/backend/{arm64,x64,riscv64}/` emit host code. The arm64 back end
  has the code slab that Shade shares between processes.
- `src/umbra/backend/block_range_information.*` records which guest address
  ranges each translated block covers, so an invalidation finds them.
- `tests/A32/testenv.h` is the environment the guest tests run in.

## Things that bite

- `UserCallbacks` has pure virtual `MemorySwap8` and `MemorySwap32`; a test
  environment or an embedder that lacks them does not compile. The guest
  examples in the guide and in `tests/A32/testenv.h` show them.
- A range invalidation must find every block in the range. It walks the range map
  from `lower_bound`; `equal_range` stops after the first block, because the
  intervals overlap and the ordering is not a strict weak ordering.
- Names that are macros or environment variables for the fault-injection hooks
  are `UMBRA_ENABLE_TEST_EMIT_FAILURE` and `UMBRA_TEST_EMIT_FAILURE`; the hooks
  compile in only with the option on.
- Do not edit `externals/` in place: each library is another project's tree.

## Conventions

- Commits: plain imperative subject, a body that says why, and the
  `Co-Authored-By: Claude <noreply@anthropic.com>` trailer.
- No personal data in tracked files: no device addresses, host names or absolute
  paths.
- Version numbers are Umbra's own, from `v0.1.0`; `CHANGELOG.md` records every
  release.
