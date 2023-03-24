#include "core/sequentialCommandGroup.h"

SequentialCommandGroup::SequentialCommandGroup(const char* name, Vector<Command*>* commands) : Command(name)
{
	_commands = commands;
}

SequentialCommandGroup::~SequentialCommandGroup()
{
	for (Command* c : *_commands)
	{
		delete c;
	}
	delete _commands->data();
	delete _commands;
}

void SequentialCommandGroup::initialize()
{
	Command::initialize();

	Log::trace("SequentialCommandGroup.initialize");
	activeCommandIdx = 0;
	activeCommand()->schedule();
}

void SequentialCommandGroup::execute()
{
	Command::execute();
	Log::trace("SequentialCommandGroup.execute");

	if (!isFinished() && !activeCommand()->isScheduled())
	{
		Log::debug("Done with letter, going to next");
		activeCommandIdx++;
	}
	
	if (!activeCommand()->isScheduled())
	{
		Log::debug("Scheduling next command");
		activeCommand()->schedule();
	}
}

bool SequentialCommandGroup::isFinished()
{
	Log::trace("SequentialCommandGroup.isFinished");
	return activeCommandIdx >= _commands->size();
}

void SequentialCommandGroup::end(bool interrupted)
{
	Command::end(interrupted);
	Log::trace("SequentialCommandGroup.end");
	if (!isFinished())
	{
		activeCommand()->end(interrupted);
	}
}

Command* SequentialCommandGroup::activeCommand()
{
	if (isFinished())
	{
		return nullptr;
	}
	else
	{
		return _commands->at(activeCommandIdx);
	}
}
