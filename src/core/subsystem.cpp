#include "core/subsystem.h"

Subsystem::Subsystem()
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
	if (activeCommand != owner)
	{
		exit(1);
	}
}
