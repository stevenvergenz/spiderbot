cmake_minimum_required(VERSION 3.26)
project("arduino-random"
	LANGUAGES CXX)

set(CMAKE_CXX_COMPILER avr-gcc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable("main")
target_sources("main"
	PUBLIC
	"src/main.cpp"
	"src/robot.cpp"
	"src/core/ticker.cpp")

target_include_directories("main" PRIVATE "src")
