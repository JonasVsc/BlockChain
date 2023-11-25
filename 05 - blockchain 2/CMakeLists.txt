cmake_minimum_required(VERSION 3.28.0)
project(blockchain)

include_directories("./include")

add_library(signatures_lib "./lib/signatures.cpp")
add_library(wallet_lib "./lib/wallet.cpp")
add_library(blockchain_lib "./lib/blockchain.cpp")
add_library(user_lib "./lib/user.cpp")
add_library(miner_lib "./lib/miner.cpp")

add_library(transaction_lib "./lib/transaction.cpp")

target_link_libraries(signatures_lib ssl crypto)
target_link_libraries(transaction_lib wallet_lib)



set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(blockchain_main "./src/blockchain_main.cpp")

target_link_libraries(blockchain_main signatures_lib wallet_lib blockchain_lib user_lib miner_lib)