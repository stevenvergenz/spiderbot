#include "core/log.h"

bool Log::isInitialized = false;

void Log::error(const char* message)
{
	log(LogLevel::error, message);
}

void Log::warn(const char* message)
{
	log(LogLevel::warning, message);
}

void Log::info(const char* message)
{
	log(LogLevel::info, message);
}

void Log::debug(const char* message)
{
	log(LogLevel::debug, message);
}

void Log::trace(const char* message)
{
	log(LogLevel::trace, message);
}

void Log::log(const LogLevel level, const char* message)
{
	if (!isInitialized)
	{
		Serial.begin(9600);
		isInitialized = true;
	}

	if (level >= Log::level)
	{
		char levelLabel =
			level == LogLevel::error ? 'E' :
			level == LogLevel::warning ? 'W' :
			level == LogLevel::info ? 'I' :
			level == LogLevel::debug ? 'D' :
			'T';

		Serial.print(levelLabel);
		Serial.print(" ");
		Serial.println(message);
	}
}
