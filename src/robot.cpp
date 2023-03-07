#include "robot.h"

const Robot Robot::instance;

Robot::Robot() : Periodic()
{
	std::cout << "Initializing robot" << std::endl;
}

void Robot::periodic()
{
	
}
