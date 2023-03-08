cmake_minimum_required(VERSION 3.5)

project(baz LANGUAGES CXX VERSION 0.0.1)

find_package(Catch2 REQUIRED)
add_executable(task4_2 task4_2.cpp)

target_link_libraries(task4_2 PRIVATE Catch2::Catch2WithMain)