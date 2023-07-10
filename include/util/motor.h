#pragma once

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <ArduinoShim.h>
#endif

class Motor
{
public:
	Motor(int id, double calibrationOffset);

	void moveToPosition(double pos, double speed = -1, double duration = -1);

private:
	int _id;
	double _offset;
};
