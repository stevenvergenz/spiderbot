#ifdef ARDUINO
#include <Arduino.h>
#else
#include <ArduinoShim.h>
#endif
#include "core/log.h"
#include "core/ticker.h"
#include "robot.h"

void setup()
{
	Log::trace("Main.setup");
	
	Robot::instance().schedule();
}

void loop()
{
	Ticker::updateTickers();
	delay(200);
}
