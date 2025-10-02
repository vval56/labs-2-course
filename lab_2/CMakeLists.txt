cmake_minimum_required(VERSION 3.10)
project(lab_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_2
    src/main.cc
    src/interaction.cc
    src/string_class.cc
    src/russian.cc
)

target_include_directories(lab_2 PRIVATE headers)