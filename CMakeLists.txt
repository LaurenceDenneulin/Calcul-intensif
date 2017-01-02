cmake_minimum_required(VERSION 2.8)

project(calcul_intensif)

set(EXECUTABLE_OUTPUT_PATH ./bin/${CMAKE_BUILD_TYPE})
include_directories(${CMAKE_PREFIX}/include)
link_directories(${CMAKE_PREFIX}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
add_executable(
    calcul_intensif
    Calcul.cpp
    Calcul.h
    main.cpp
)