cmake_minimum_required(VERSION 3.26)
project(arduino-random
	LANGUAGES C CXX)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


## Compile c files
#avr-gcc {compiler.c.flags} -mmcu={build.mcu} -DF_CPU={build.f_cpu} -DARDUINO={runtime.ide.version} -DARDUINO_{build.board} -DARDUINO_ARCH_{build.arch} {compiler.c.extra_flags} {build.extra_flags} {includes} "{source_file}" -o "{object_file}"

## Compile c++ files
#avr-g++ {compiler.cpp.flags} -mmcu={build.mcu} -DF_CPU={build.f_cpu} -DARDUINO={runtime.ide.version} -DARDUINO_{build.board} -DARDUINO_ARCH_{build.arch} {compiler.cpp.extra_flags} {build.extra_flags} {includes} "{source_file}" -o "{object_file}"

## Compile S files
#recipe.S.o.pattern="{compiler.path}{compiler.c.cmd}" {compiler.S.flags} -mmcu={build.mcu} -DF_CPU={build.f_cpu} -DARDUINO={runtime.ide.version} -DARDUINO_{build.board} -DARDUINO_ARCH_{build.arch} {compiler.S.extra_flags} {build.extra_flags} {includes} "{source_file}" -o "{object_file}"
#


set(COMPILER_FLAGS -c -g -Os -w -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto)
set(BUILD_MCU -mmcu=avr5 -D__AVR_ATmega328P__ -D__AVR_DEVICE_NAME__=atmega328p)
set(BUILD_F_CPU 16000000L)
set(RUNTIME_IDE_VERSION 10806)
set(BUILD_BOARD AVR_DUEMILANOVE)
set(BUILD_ARCH ARM)
add_compile_options(${COMPILER_FLAGS} ${BUILD_MCU} -DF_CPU=${BUILD_F_CPU} -DARDUINO=${RUNTIME_IDE_VERSION} -DARDUINO_${BUILD_BOARD} -DARDUINO_ARCH_${BUILD_ARCH})


add_executable(test src/test.c)
target_link_libraries(test arduino-core)

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
	${ARDUINO_PATH}/hardware/avr/1.8.6/variants/standard/)
