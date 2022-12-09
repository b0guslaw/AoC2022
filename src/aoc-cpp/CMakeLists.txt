cmake_minimum_required(VERSION 3.20)
project(aoc-cpp VERSION 0.1.0)

SET(CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE} CACHE STRING "" FORCE)

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

target_compile_options(aoc-cpp PRIVATE -Wall -Wextra -Wpedantic -Werror)

if (BUILD_PROFILE)
  add_subdirectory(profile)
endif()

target_link_libraries(aoc-cpp
                    fmt::fmt 
                    Threads::Threads)
