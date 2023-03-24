#include "core/command.h"

Command::Command()
{
	isInitialized = false;
}

Command::~Command()
{
	
}

void Command::tick()
{
	if (!isInitialized)
	{
		initialize();
		isInitialized = true;
	}

	execute();

	if (isFinished())
	{
		end(false);
	}
}

void Command::initialize()
{
	isInitialized = true;
}

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
