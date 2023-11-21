cmake_minimum_required(VERSION 3.28.0)
project(hash)

include_directories("./include")

add_library(block_lib "./lib/block.cpp")
add_library(hash_lib "./lib/hash.cpp")
target_link_libraries(hash_lib ssl crypto)
target_link_libraries(block_lib hash_lib)

set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(block_main "./src/block_main.cpp")

target_link_libraries(block_main hash_lib block_lib)