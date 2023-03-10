#include "blink.h"

BlinkCommand::BlinkCommand() : Command()
{

}

void BlinkCommand::initialize()
{
	addRequirements(&Led::instance());
	counter = 0;
}

void BlinkCommand::execute()
{
	if (counter == 0)
	{
		Led::instance().setLit(!Led::instance().isLit());
	}
	counter = (counter + 1) % 10000;
}

bool BlinkCommand::isFinished()
{
	return false;
}

void BlinkCommand::end(bool isInterrupted)
{
	Led::instance().setLit(false);
}
