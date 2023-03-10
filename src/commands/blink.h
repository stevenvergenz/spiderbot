#pragma once
#include "../core/command.h"
#include "../subsystems/led.h"

class BlinkCommand : public Command
{
public:
	BlinkCommand();

protected:
	void initialize();
	void execute();
	bool isFinished();
	void end(bool isInterrupted);

private:
	int counter = 0;
};
