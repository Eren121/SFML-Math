cmake_minimum_required(VERSION 3.16)
set(EXE SFML-Math)
project(${EXE})

set(CMAKE_CXX_STANDARD 17)
set(TESTS_MAIN catch_main.cpp)
set(TESTS_SRC
    do_not_conflict.cpp
    mixed_types.cpp
    with_scalar.cpp
    to_string.cpp)

add_executable(${EXE}
    ${TESTS_MAIN}
    ${TESTS_SRC})

target_include_directories(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(${EXE} sfml-system sfml-graphics)