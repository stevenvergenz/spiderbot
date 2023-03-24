#include "commands/blink.h"

BlinkCommand::BlinkCommand(Pattern pattern, const char* name)
{
	_pattern = pattern;
	_name = name;
}

void BlinkCommand::initialize()
{
	Log::trace("BlinkCommand.initialize");

	Command::initialize();
	addRequirements(&Led::instance());
	_counter = 0;
}

void BlinkCommand::execute()
{
	int ticks = (_pattern & 0b1) ? BlinkCommand::s_longTicks : BlinkCommand::s_shortTicks;
	if (_counter < ticks)
	{
		Led::instance().setLit(true);
		_counter++;
	}
	else if (_counter == ticks)
	{
		Led::instance().setLit(false);
		_counter++;
	}
	else
	{
		_pattern = _pattern >> 1;
		_counter = 0;
	}
}

bool BlinkCommand::isFinished()
{
	return _pattern <= 0b1;
}

void BlinkCommand::end(bool isInterrupted)
{
	Log::trace("BlinkCommand.end");

	Command::end(isInterrupted);
	Led::instance().setLit(false);
}
