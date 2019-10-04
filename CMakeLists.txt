cmake_minimum_required(VERSION 3.0)

project(spinnercpp LANGUAGES CXX)

list( APPEND CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -ggdb")

add_subdirectory(tests)
add_subdirectory(example)

