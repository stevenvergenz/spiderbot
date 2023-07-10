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

	Log.traceln("SequentialCommandGroup.initialize");
	activeCommandIdx = 0;
	activeCommand()->schedule();
}

void SequentialCommandGroup::execute()
{
	Command::execute();
	Log.traceln("SequentialCommandGroup.execute");

	Command* command = activeCommand();
	if (command != nullptr && !command->isScheduled())
	{
		Log.verboseln("Done with letter, going to next");
		activeCommandIdx++;
	}
	
	command = activeCommand();
	if (command != nullptr && !command->isScheduled())
	{
		Log.verboseln("Scheduling next command");
		command->schedule();
	}
}

bool SequentialCommandGroup::isFinished()
{
	Log.traceln("SequentialCommandGroup.isFinished (%d of %d)", activeCommandIdx+1, _commands->size());
	return activeCommandIdx >= _commands->size();
}

void SequentialCommandGroup::end(bool interrupted)
{
	Command::end(interrupted);
	Log.traceln("SequentialCommandGroup.end");
	if (activeCommand() != nullptr && interrupted)
	{
		activeCommand()->end(true);
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
