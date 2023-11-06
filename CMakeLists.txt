
cmake_minimum_required(VERSION 3.28.0)
project(Blockchain)

#librarys
add_library(Money ./lib/money.cpp)


# create executables
add_executable(driver ./src/driver.cpp)
add_executable(app ./src/main.cpp)
add_executable(example ./src/hash.cpp)

include_directories("C:/msys64/ucrt64/include")
include_directories(include)


# link_directories("C:/msys64/ucrt64/lib")



# important link library to executable manually

target_link_libraries(example ssl crypto)
target_link_libraries(driver Money)