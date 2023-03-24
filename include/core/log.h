#pragma once
#ifdef ARDUINO
#include <Arduino.h>
#else
#include <ArduinoShim.h>
#endif

enum LogLevel
{
	error = 0,
	warning = 1,
	info = 2,
	debug = 3,
	trace = 4
};

class Log
{
public:
	static constexpr LogLevel level = LogLevel::trace;

	static void error(const char* message);
	static void warn(const char* message);
	static void info(const char* message);
	static void debug(const char* message);
	static void trace(const char* message);

private:
	static bool isInitialized;
	static void log(const LogLevel level, const char* message);
};
