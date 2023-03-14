#pragma once
#include "../core/command.h"
#include "../subsystems/led.h"

/**
Pattern is a bit-field whose most significant bit is 1, which is read least to most significant
*/
typedef uint8 Pattern;

class BlinkCommand : public Command
{
public:
	BlinkCommand(Pattern pattern);

protected:
	void initialize();
	void execute();
	bool isFinished();
	void end(bool isInterrupted);

private:
	static constexpr uint8 s_shortTicks = 1;
	static constexpr uint8 s_longTicks = 4;

	int _counter = 0;
	Pattern _pattern;
};
