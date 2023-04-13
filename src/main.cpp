#ifdef ARDUINO
#include <Arduino.h>
#else
#include <ArduinoShim.h>
#endif
#include <ArduinoLog.h>
#include "core/ticker.h"
#include "robot.h"

void setup()
{
	Serial.begin(9600);
	Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);
	Log.traceln("Main.setup");
	
	Robot::instance().schedule();
}

void loop()
{
	Ticker::updateTickers();
	delay(100);
}
