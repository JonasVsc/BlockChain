cmake_minimum_required(VERSION 3.28.0)
project(merkle_tree)

include_directories("./include")

set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(p2p_main "./src/p2p_main.cpp")

target_link_libraries(p2p_main -lws2_32 -pthread)