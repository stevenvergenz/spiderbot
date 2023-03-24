#pragma once
#include <stdlib.h>
#include "ticker.h"

class Subsystem;

#include "command.h"

class Subsystem : public Ticker
{
public:
	virtual void tick();
	void claim(Command* owner);
	void release(Command* owner);

protected:
	Subsystem(const char* name);
	~Subsystem();

private:
	Command* activeCommand;
};
