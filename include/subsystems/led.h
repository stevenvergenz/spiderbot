#pragma once

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <ArduinoShim.h>
#endif
#include "../core/subsystem.h"
#include "../constants.h"

class Led : public Subsystem
{
public:
	static Led& instance();
	bool isLit();
	void setLit(bool lit);

private:
	static Led s_inst;
	bool _isLit;
	Led();
};
