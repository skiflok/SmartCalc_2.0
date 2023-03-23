
# 'Google_test' is the subproject name

include(FetchContent)
FetchContent_Declare(
        googletest
        Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(HEADER_FILES
        ../model/model.h
        ../model/kernel/validator.h
        ../model/kernel/parser.h
        ../model/kernel/calculators/calculator.h
        ../model/kernel/calculators/calculator_plot.h
        ../model/kernel/calculators/calculator_deposit.h
        ../model/kernel/calculators/calculator_credit.h
        )

set(SOURCE_FILES
        ../model/model.cc
        ../model/kernel/validator.cc
        ../model/kernel/parser.cc
        ../model/kernel/calculators/calculator.cc
        ../model/kernel/calculators/calculator_plot.cc
        ../model/kernel/calculators/calculator_deposit.cc
        ../model/kernel/calculators/calculator_credit.cc
        )

add_library(smart_calc STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(unit_tests tests.cc)

target_link_libraries(unit_tests
        smart_calc
        gtest
        gtest_main
        )

add_test(test_all unit_tests)