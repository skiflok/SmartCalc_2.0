# 'Google_test' is the subproject name
cmake_minimum_required(VERSION 3.21.1)
project(Google_tests)

include(FetchContent)
FetchContent_Declare(
        googletest
        Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


#add_executable(Google_Tests_run tests_map.cc ../src/sorted_container/associative_container/s21_map.h)


#set(HEADER_FILES
#        ../model/kernel/parser.h
#        )
#
set(SOURCE_FILES
        ../model/kernel/validator.cc
        ../model/kernel/parser.cc
        ../model/kernel/calculator.cc
        )

#add_executable(s21_matrix_cpp
#        s21_matrix_oop.cpp
#        s21_matrix_oop.h)

#add_library(parser STATIC ${SOURCE_FILES} ${HEADER_FILES})


add_executable(Google_Tests_run tests.cc ${SOURCE_FILES})

target_link_libraries(Google_Tests_run gtest gtest_main)
