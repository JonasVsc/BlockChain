cmake_minimum_required(VERSION 3.28.0)
project(merkle_tree)

include_directories("./include")

add_library(hash_lib "./lib/hash.cpp")
target_link_libraries(hash_lib ssl crypto)

set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(p2p_main "./src/p2p_main.cpp")

target_link_libraries(p2p_main hash_lib -lws2_32 -pthread)