cmake_minimum_required(VERSION 3.15)

project(TonYogourt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include) 

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(TonYogourt ${SOURCES} "src/Yogourt/YogourtGrec.cpp" "include/Yogourt/YogourtNature.h" "include/Yogourt/YogourtGrec.h")
