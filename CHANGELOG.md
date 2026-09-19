# Changelog

All notable changes to this project are recorded here.
The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/).

## [Unreleased]

### Added
- A test that translates three blocks, changes them all and invalidates them with
  one range.

### Changed
- The project is named Umbra: the namespace, the CMake targets and options, the
  include path, the directories and the documentation.
- The fault-injection hooks are named for the core: `UMBRA_ENABLE_TEST_EMIT_FAILURE`
  and `UMBRA_TEST_EMIT_FAILURE`.
- The license file is `LICENSE`.

### Fixed
- The guest test environments implement `MemorySwap8` and `MemorySwap32`; the test
  suite did not compile without them.
- A range invalidation finds every block in the range, not only the first.

### Removed
- The CI workflows the tree was forked with; they ran against other repositories.
