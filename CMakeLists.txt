cmake_minimum_required(VERSION 3.5)

project(hash-search LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hash-search main.cpp
               hash-library/sha256.h hash-library/sha256.cpp)
