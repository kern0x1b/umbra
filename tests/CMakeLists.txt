include(TargetArchitectureSpecificSources)

add_executable(umbra_tests
    fp/FPToFixed.cpp
    fp/FPValue.cpp
    fp/mantissa_util_tests.cpp
    fp/unpacked_tests.cpp
    rand_int.h
)

if ("A32" IN_LIST UMBRA_FRONTENDS)
    target_sources(umbra_tests PRIVATE
        A32/test_arm_disassembler.cpp
        A32/test_arm_instructions.cpp
        A32/test_coprocessor.cpp
        A32/test_svc.cpp
        A32/test_thumb_instructions.cpp
        A32/testenv.h
        decoder_tests.cpp
    )
endif()

if ("A64" IN_LIST UMBRA_FRONTENDS)
    target_link_libraries(umbra_tests PRIVATE merry::oaknut)

    target_sources(umbra_tests PRIVATE
        A64/a64.cpp
        A64/fibonacci.cpp
        A64/fp_min_max.cpp
        A64/misaligned_page_table.cpp
        A64/test_invalidation.cpp
        A64/testenv.h
    )
endif()

if (UMBRA_TESTS_USE_UNICORN)
    target_link_libraries(umbra_tests PRIVATE Unicorn::Unicorn)

    target_sources(umbra_tests PRIVATE
        fuzz_util.cpp
        fuzz_util.h
    )

    if ("A32" IN_LIST UMBRA_FRONTENDS)
        target_sources(umbra_tests PRIVATE
            A32/fuzz_arm.cpp
            A32/fuzz_thumb.cpp
            unicorn_emu/a32_unicorn.cpp
            unicorn_emu/a32_unicorn.h
        )
    endif()

    if ("A64" IN_LIST UMBRA_FRONTENDS)
        target_sources(umbra_tests PRIVATE
            A64/fuzz_with_unicorn.cpp
            A64/verify_unicorn.cpp
            unicorn_emu/a64_unicorn.cpp
            unicorn_emu/a64_unicorn.h
        )
    endif()
endif()

if ("riscv" IN_LIST ARCHITECTURE)
    target_link_libraries(umbra_tests PRIVATE biscuit::biscuit)
endif()

if ("x86_64" IN_LIST ARCHITECTURE)
    target_link_libraries(umbra_tests PRIVATE xbyak::xbyak)

    target_architecture_specific_sources(umbra_tests "x86_64"
        x64_cpu_info.cpp
    )

    if (NOT MSVC AND NOT UMBRA_MULTIARCH_BUILD)
        target_sources(umbra_tests PRIVATE
            rsqrt_test.cpp
            rsqrt_test_fn.s
        )
    endif()
endif()

include(CreateDirectoryGroups)

if (("A32" IN_LIST UMBRA_FRONTENDS) AND ("A64" IN_LIST UMBRA_FRONTENDS))
    add_executable(umbra_print_info
        print_info.cpp
    )

    create_target_directory_groups(umbra_print_info)

    target_link_libraries(umbra_print_info PRIVATE umbra Boost::boost fmt::fmt merry::mcl)
    target_include_directories(umbra_print_info PRIVATE . ../src)
    target_compile_options(umbra_print_info PRIVATE ${UMBRA_CXX_FLAGS})
    target_compile_definitions(umbra_print_info PRIVATE FMT_USE_USER_DEFINED_LITERALS=1)
endif()

if (("A32" IN_LIST UMBRA_FRONTENDS) AND ("A64" IN_LIST UMBRA_FRONTENDS))
    add_executable(umbra_test_generator
        fuzz_util.cpp
        fuzz_util.h
        test_generator.cpp
    )

    create_target_directory_groups(umbra_test_generator)

    target_link_libraries(umbra_test_generator PRIVATE umbra Boost::boost fmt::fmt merry::mcl)
    target_include_directories(umbra_test_generator PRIVATE . ../src)
    target_compile_options(umbra_test_generator PRIVATE ${UMBRA_CXX_FLAGS})
    target_compile_definitions(umbra_test_generator PRIVATE FMT_USE_USER_DEFINED_LITERALS=1)
endif()

if (("A32" IN_LIST UMBRA_FRONTENDS) AND ("A64" IN_LIST UMBRA_FRONTENDS))
    add_executable(umbra_test_reader
        test_reader.cpp
    )

    create_target_directory_groups(umbra_test_reader)

    target_link_libraries(umbra_test_reader PRIVATE umbra Boost::boost fmt::fmt merry::mcl)
    target_include_directories(umbra_test_reader PRIVATE . ../src)
    target_compile_options(umbra_test_reader PRIVATE ${UMBRA_CXX_FLAGS})
    target_compile_definitions(umbra_test_reader PRIVATE FMT_USE_USER_DEFINED_LITERALS=1)
endif()

create_target_directory_groups(umbra_tests)

target_link_libraries(umbra_tests PRIVATE umbra Boost::boost Catch2::Catch2WithMain fmt::fmt merry::mcl)
target_include_directories(umbra_tests PRIVATE . ../src)
target_compile_options(umbra_tests PRIVATE ${UMBRA_CXX_FLAGS})
target_compile_definitions(umbra_tests PRIVATE FMT_USE_USER_DEFINED_LITERALS=1)

add_test(umbra_tests umbra_tests --durations yes)
