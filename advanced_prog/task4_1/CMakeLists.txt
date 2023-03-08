cmake_minimum_required(VERSION 3.5)

project(baz LANGUAGES CXX VERSION 0.0.1)

find_package(Catch2 REQUIRED)
add_executable(task4_1 task4_1.cpp)

target_link_libraries(task4_1 PRIVATE Catch2::Catch2WithMain)