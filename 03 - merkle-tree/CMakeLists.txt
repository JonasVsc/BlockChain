cmake_minimum_required(VERSION 3.28.0)
project(merkle_tree)

include_directories("./include")

add_library(hash_lib "./lib/hash.cpp")
target_link_libraries(hash_lib ssl crypto)

set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(merkle_tree_main "./src/merkle_tree_main.cpp")

target_link_libraries(merkle_tree_main hash_lib)