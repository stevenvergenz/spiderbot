#include "robot.h"

Robot* Robot::_instance = nullptr;

Robot& Robot::instance()
{
	if (_instance == nullptr)
	{
		_instance = new Robot();
	}
	return *_instance;
}

Robot::Robot() : _blinkMorse("SOS")
{
	
}

void Robot::schedule()
{
	Log::trace("Robot.schedule");

	Ticker::schedule();
	_blinkMorse.schedule();
}

void Robot::tick()
{
	
}

void Robot::unschedule()
{
	Ticker::unschedule();
	_blinkMorse.unschedule();
}
