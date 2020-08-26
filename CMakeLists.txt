cmake_minimum_required(VERSION 3.0)

project(genom)
set (THREADS_PREFER_PTHREAD_FLAG ON)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast  -march=native")

find_package(Threads REQUIRED)

file(GLOB SRC
    "src/*.h"
    "src/*.cpp"
)

add_executable(genom ${SRC})
target_link_libraries(genom PRIVATE Threads::Threads)

install(TARGETS genom RUNTIME DESTINATION bin)
