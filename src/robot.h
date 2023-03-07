#pragma once
#include <memory>
#include <iostream>
#include "core/periodic.h"

class Robot : public Periodic
{
public:
	static const Robot instance;
	
	Robot();
	void periodic();
};
