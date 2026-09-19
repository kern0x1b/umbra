# Third-party components

Everything under `externals/` is another project's tree and keeps its own license
file and notices; do not edit it in place. Umbra's own code is 0BSD, see `LICENSE`.

| Component | Version | License | Copyright | Where |
| --- | --- | --- | --- | --- |
| biscuit | 0.14.0 | MIT | 2021 Lioncash | `externals/biscuit` |
| Catch2 | as vendored | BSL-1.0 | Two Blue Cubes Ltd. | `externals/catch` |
| fmt | 12.1.0 | MIT | 2012 - present Victor Zverovich and {fmt} contributors | `externals/fmt` |
| mcl | 0.1.12 | MIT | 2022 merryhime | `externals/mcl` |
| oaknut | 2.0.2 | MIT | 2022 - 2024 merryhime | `externals/oaknut` |
| robin-map | 0.6.2 | MIT | 2017 Thibaut Goetghebuer-Planchon | `externals/robin-map` |
| xbyak | as vendored | BSD-3-Clause | 2007 MITSUNARI Shigeo | `externals/xbyak`, notice in `COPYRIGHT` |
| Zycore | 1.4.0 | MIT | 2018 - 2020 Florian Bernd | `externals/zycore` |
| Zydis | 4.0.0 | MIT | 2014 - 2021 Florian Bernd | `externals/zydis` |

Not in the tree, needed to build: the Boost headers (Boost Software License 1.0),
for example from [shade-boost](https://github.com/kern0x1b/shade-boost).

A binary built from this tree carries these notices with it; the BSD-3-Clause and
MIT texts require that.
