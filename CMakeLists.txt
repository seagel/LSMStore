cmake_minimum_required(VERSION 3.20)
project(LSMStore)

set(CMAKE_CXX_STANDARD 14)

add_executable(LSMStore main.cpp MemTable.cpp MemTable.h)
