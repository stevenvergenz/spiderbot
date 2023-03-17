#include "core/sequentialCommandGroup.h"

SequentialCommandGroup::SequentialCommandGroup(Vector<Command*>* commands) : Command()
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

	activeCommandIdx = 0;
}

void SequentialCommandGroup::execute()
{
	Command::execute();

	if (!isFinished() && !activeCommand()->isScheduled())
	{
		activeCommandIdx++;
	}
	
	if (!isFinished())
	{
		activeCommand()->schedule();
	}
}

bool SequentialCommandGroup::isFinished()
{
	return _commands->size() <= activeCommandIdx;
}

void SequentialCommandGroup::end(bool interrupted)
{
	Command::end(interrupted);
	
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
