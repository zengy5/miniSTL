cmake_minimum_required(VERSION 3.0.2)
project(MINISTL)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

include_directories(include)

add_executable(myVector src/myVector.cpp)
add_executable(myList src/myList.cpp)
add_executable(myDeque src/myDeque.cpp)
add_executable(myHash src/myHashTable.cpp)
add_executable(myTree src/myRedBlackTree.cpp)
add_executable(mySet src/mySet.cpp include/RedBlackTree.h)
add_executable(myMSet src/myMultiSet.cpp include/RedBlackTree.h)
add_executable(myMap src/myMap.cpp include/RedBlackTree.h)
add_executable(myUnSet src/myUnSet.cpp include/HashTable.h)