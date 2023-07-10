#include "core/command.h"

Command::Command(const char* name) : Ticker(name)
{
	isInitialized = false;
}

Command::~Command()
{
	
}

void Command::tick()
{
	Log.traceln("Command.tick");
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
	Log.traceln("Command.initialize");
	isInitialized = true;
}

void Command::execute() { }

bool Command::isFinished() { return true; }

void Command::end(bool isInterrupted)
{
	Log.traceln("Command.end");
	if (requirement != nullptr)
	{
		requirement->release(this);
		requirement = nullptr;
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
