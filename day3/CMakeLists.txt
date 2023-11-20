cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(day3)

add_executable(day3 main.cc ../include/readfile.cc)

target_include_directories(day3 PRIVATE
  ../include
)
