#pragma once
#include "periodic.h"
#include "command.h"

class Subsystem : public Periodic
{
public:
	void claim(Command claimant);

private:
	Command* activeCommand;
};
