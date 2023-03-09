#pragma once
#include "core/ticker.h"

class Robot : public Ticker
{
public:
	static const Robot instance;
	
	Robot();
	void tick();
};
