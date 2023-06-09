#pragma once
#ifdef ARDUINO
#include <Arduino.h>
#else
#include <ArduinoShim.h>
#endif
#include <ArduinoLog.h>
#include "core/command.h"
#include "subsystems/led.h"

/**
* Pattern is a bit-field whose most significant bit is 1, which is read least to most significant,
* with 1 indicating a long flash and 0 a short one
*/
typedef uint8_t Pattern;

class BlinkCommand : public Command
{
public:
	BlinkCommand(const char* name, Pattern pattern);

protected:
	void initialize();
	void execute();
	bool isFinished();
	void end(bool isInterrupted);

private:
	static constexpr uint8_t s_shortTicks = 2;
	static constexpr uint8_t s_longTicks = 4;

	int _counter = 0;
	Pattern _pattern;
	Pattern _activePattern;
};
