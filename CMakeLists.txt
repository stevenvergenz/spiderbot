cmake_minimum_required(VERSION 3.26)
project(arduino-random
	LANGUAGES C CXX)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-mmcu=atmega328p)

add_executable(test src/test.c)

add_executable(main)
target_sources(main
	PRIVATE
	src/main.cpp
	src/robot.cpp
	src/core/ticker.cpp
	src/core/command.cpp
	src/core/subsystem.cpp
	src/commands/blink.cpp
	src/subsystems/led.cpp)

target_include_directories(main PRIVATE src)
target_link_libraries(main arduino-core)

set(ARDUINO_PATH /home/steven/.arduino15/packages/arduino)

set(ARDUINO_CORE_SOURCES)
file(GLOB ARDUINO_CORE_SOURCES ${ARDUINO_PATH}/hardware/avr/1.8.6/cores/arduino/*.cpp)
file(GLOB ARDUINO_CORE_SOURCES ${ARDUINO_PATH}/hardware/avr/1.8.6/cores/arduino/*.c)

add_library(arduino-core STATIC ${ARDUINO_CORE_SOURCES})
set_target_properties(arduino-core PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(arduino-core
	PUBLIC
	${ARDUINO_PATH}/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/avr/include/
	${ARDUINO_PATH}/hardware/avr/1.8.6/cores/arduino/
	${ARDUINO_PATH}/hardware/avr/1.8.6/variants/mega/)
