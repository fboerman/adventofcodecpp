cmake_minimum_required(VERSION 3.27)
project(adventofcode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

#find_package(Arrow REQUIRED)

#message(STATUS "Arrow version: ${ARROW_VERSION}")
#message(STATUS "Arrow SO version: ${ARROW_FULL_SO_VERSION}")

add_executable(adventofcode main.cpp
        day1.cpp
        days.h)

#target_link_libraries(adventofcode PRIVATE Arrow::arrow_shared)
