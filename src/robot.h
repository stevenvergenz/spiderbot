#pragma once
#include "core/ticker.h"
#include "commands/blinkMorse.h"

class Robot : public Ticker
{
public:
	static Robot instance;
	
	Robot();
	void tick();

private:
	BlinkMorseCommand blinkMorse;
};
