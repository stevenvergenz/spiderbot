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

Robot::Robot() : Ticker("Robot"), _blinkMorse("SOS")
{
	
}

void Robot::schedule()
{
	Log.trace("Robot.schedule");
	Ticker::schedule();
	_blinkMorse.schedule();
}

void Robot::tick()
{
	if (!_blinkMorse.isScheduled())
	{
		_blinkMorse.schedule();
	}
}

void Robot::unschedule()
{
	Ticker::unschedule();
	_blinkMorse.unschedule();
}
