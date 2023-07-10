#include "core/subsystem.h"

Subsystem::Subsystem(const char* name) : Ticker(name)
{
	schedule();
}

Subsystem::~Subsystem()
{
	unschedule();
}

void Subsystem::tick() {}

void Subsystem::claim(Command* owner)
{
	if (activeCommand != nullptr)
	{
		activeCommand->end(true);
	}
	activeCommand = owner;
}

void Subsystem::release(Command* owner)
{
	if (activeCommand != nullptr && activeCommand != owner)
	{
		Log.warningln("The wrong command is releasing subsystem %s", name);
	}
	activeCommand = nullptr;
}
