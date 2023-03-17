#include "core/command.h"

Command::Command()
{
	isInitialized = false;
}

void Command::tick()
{
	if (!isInitialized)
	{
		initialize();
	}

	execute();

	if (isFinished())
	{
		end(false);
	}
}

void Command::initialize() { }

void Command::execute() { }

bool Command::isFinished() { return true; }

void Command::end(bool isInterrupted)
{
	if (requirement != nullptr)
	{
		requirement->release(this);
	}
	unschedule();
	isInitialized = false;
}

void Command::addRequirements(Subsystem* req)
{
	if (req != nullptr)
	{
		requirement = req;
		requirement->claim(this);
	}
}
