cmake_minimum_required(VERSION 3.21)
project(MyString)

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-Wall)

add_executable(MyString main.cpp MyString.cpp MyString.h)
