cmake_minimum_required(VERSION 3.28.0)
project(blockchain)

include_directories("./include")

add_library(hash_lib "./lib/hash.cpp")
add_library(blockchain_lib "./lib/blockchain.cpp")
target_link_libraries(hash_lib ssl crypto)
target_link_libraries(blockchain_lib hash_lib)


set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(blockchain_main "./src/blockchain_main.cpp")

target_link_libraries(blockchain_main hash_lib blockchain_lib)