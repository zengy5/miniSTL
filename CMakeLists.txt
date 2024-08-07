cmake_minimum_required(VERSION 3.0.2)
project(MINISTL)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(myVector src/myVector.cpp)
add_executable(myList src/myList.cpp)
add_executable(myDeque src/myDeque.cpp)
add_executable(myHash src/myHashTable.cpp)
add_executable(myTree src/myRedBlackTree.cpp)