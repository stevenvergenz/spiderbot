#pragma once
#include <Arduino.h>
#include "../core/subsystem.h"

class Led : public Subsystem
{
public:
	static Led& instance();
	bool isLit();
	void setLit(bool lit);

private:
	static Led s_inst;
	Led();
};
