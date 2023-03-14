#include <Arduino.h>
#include "core/ticker.h"
#include "robot.h"

int main(int argc, char **argv)
{
	Serial.begin(9600);
	Serial.println("Starting");
	
	Robot robot;

	while(true)
	{
		Ticker::updateTickers();
		delay(200);
	}

	return 0;
}
