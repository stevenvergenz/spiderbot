#pragma once

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <ArduinoShim.h>
#endif
#include "../core/subsystem.h"
#include "../constants.h"

class Leg : public Subsystem
{
public:
	static Leg& instance();

private:
	static Leg s_inst;
	Leg();
};
