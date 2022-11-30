cmake_minimum_required(VERSION 3.0.0)
project(aoc-cpp VERSION 0.1.0)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(COPY ${CMAKE_SOURCE_DIR}/../../res DESTINATION ${CMAKE_BINARY_DIR})

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

find_package(Threads REQUIRED)

add_executable(aoc-cpp main.cpp)

if (UNIX) 
  target_compile_options(aoc-cpp PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

target_link_libraries(aoc-cpp
                    fmt::fmt 
                    Threads::Threads)
