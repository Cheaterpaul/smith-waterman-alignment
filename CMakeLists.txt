cmake_minimum_required(VERSION 3.0)

project(genom)

add_executable(genom main.cpp)

install(TARGETS genom RUNTIME DESTINATION bin)
