cmake_minimum_required(VERSION 3.25)
project(TUBES_STD)

set(CMAKE_CXX_STANDARD 17)

add_executable(TUBES_STD main.cpp TUBES.h funcsdokter.cpp funcsrelasi.cpp funcspasien.cpp)
