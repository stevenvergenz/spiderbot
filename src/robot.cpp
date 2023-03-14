#include "robot.h"

Robot::Robot() : Ticker(), blinkMorse("SOS")
{
	blinkMorse.schedule();
}

void Robot::tick()
{
	
}
