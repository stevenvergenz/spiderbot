cmake_minimum_required(VERSION 3.26)
project(arduino-random
	LANGUAGES C CXX)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(COMPILER_FLAGS -c -g -Os -w -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto)
set(BUILD_MCU -mmcu=avr5 -D__AVR_ATmega328P__ -D__AVR_DEVICE_NAME__=atmega328p)
set(BUILD_F_CPU 16000000L)
set(RUNTIME_IDE_VERSION 10806)
set(BUILD_BOARD AVR_DUEMILANOVE)
set(BUILD_ARCH AVR)
add_compile_options(${COMPILER_FLAGS} ${BUILD_MCU} -DF_CPU=${BUILD_F_CPU} -DARDUINO=${RUNTIME_IDE_VERSION} -DARDUINO_${BUILD_BOARD} -DARDUINO_ARCH_${BUILD_ARCH})


#############################
### Main outputs
#############################

add_executable(test-build src/test.c)
target_link_libraries(test-build arduino-core)

add_executable(test-deploy src/test-deploy.c)

add_executable(main)
target_sources(main
	PRIVATE
	src/main.cpp
	src/robot.cpp
	src/core/ticker.cpp
	src/core/command.cpp
	src/core/sequentialCommandGroup.cpp
	src/core/subsystem.cpp
	src/commands/blink.cpp
	src/commands/blinkMorse.cpp
	src/subsystems/led.cpp
)

target_include_directories(main PRIVATE src)
target_link_libraries(main arduino-core vector)

add_custom_command(TARGET main POST_BUILD
	COMMAND avr-objcopy -O ihex -j.text -j.data $<TARGET_FILE:main> $<TARGET_FILE:main>.hex
)


################################
### Libraries
################################

set(ARDUINO_PATH /home/steven/.arduino15/packages/arduino)

set(ARDUINO_CORE_SOURCES)
file(GLOB ARDUINO_CORE_SOURCES ${ARDUINO_PATH}/hardware/avr/1.8.6/cores/arduino/*.cpp)
file(GLOB ARDUINO_CORE_SOURCES ${ARDUINO_PATH}/hardware/avr/1.8.6/cores/arduino/*.c)
file(GLOB ARDUINO_CORE_SOURCES ${ARDUINO_PATH}/hardware/avr/1.8.6/cores/arduino/*.S)

add_library(arduino-core STATIC ${ARDUINO_CORE_SOURCES})
set_target_properties(arduino-core PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(arduino-core
	PUBLIC
	${ARDUINO_PATH}/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/avr/include/
	${ARDUINO_PATH}/hardware/avr/1.8.6/variants/standard/
	${ARDUINO_PATH}/hardware/avr/1.8.6/cores/arduino/
)



add_library(array STATIC lib/array/src/Array/Array.cpp)
target_include_directories(array PUBLIC lib/array/src)
target_link_libraries(array arduino-core)



add_library(vector STATIC lib/vector/src/Vector/Vector.cpp)
target_include_directories(vector PUBLIC lib/vector/src)
target_link_libraries(vector arduino-core)
