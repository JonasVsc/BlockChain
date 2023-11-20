cmake_minimum_required(VERSION 3.28.0)
project(hash)

include_directories("./include")

set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(hash_main "./src/hash_main.cpp")

target_link_libraries(hash_main ssl crypto)