cmake_minimum_required(VERSION 3.26)
project("arduino-random"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable("main" "src/main.cpp")
target_include_directories("main" PRIVATE "src")
