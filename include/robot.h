#pragma once
#include <ArduinoLog.h>
#include "core/ticker.h"
#include "commands/blinkMorse.h"

class Robot : public Ticker
{
public:
	static Robot& instance();
	
	void schedule();
	void tick();
	void unschedule();

private:
	static Robot* _instance;
	
	BlinkMorseCommand _blinkMorse;

	Robot();
};
