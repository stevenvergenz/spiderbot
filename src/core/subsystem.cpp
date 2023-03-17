#include "core/subsystem.h"

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
