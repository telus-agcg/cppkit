cmake_minimum_required (VERSION 2.8.12)

project(bzip2)

include(FetchContent)

FetchContent_Declare(
    bzip2-src
    GIT_REPOSITORY https://gitlab.com/bzip2/bzip2
    GIT_TAG 962d60610cb31e0f294a834e55ebb355be55d05a
)

FetchContent_MakeAvailable(bzip2-src)

if(NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Debug)
endif()

add_library (bzip2 ${bzip2-src_SOURCE_DIR}/bzlib.h
                   ${bzip2-src_SOURCE_DIR}/bzlib_private.h
                   ${bzip2-src_SOURCE_DIR}/blocksort.c
                   ${bzip2-src_SOURCE_DIR}/huffman.c
                   ${bzip2-src_SOURCE_DIR}/crctable.c
                   ${bzip2-src_SOURCE_DIR}/randtable.c
                   ${bzip2-src_SOURCE_DIR}/compress.c
                   ${bzip2-src_SOURCE_DIR}/decompress.c
                   ${bzip2-src_SOURCE_DIR}/bzlib.c)

target_include_directories(bzip2
  PUBLIC
  ${bzip2-src_SOURCE_DIR})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(bzip2 PUBLIC "-O0")
    target_compile_options(bzip2 PUBLIC "-ggdb")
else(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(bzip2 PUBLIC "-O3")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

