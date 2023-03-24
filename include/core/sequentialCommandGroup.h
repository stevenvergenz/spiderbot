#pragma once
#include <Vector.h>
#include "command.h"

class SequentialCommandGroup : public Command
{
public:
	void end(bool interrupted);
	~SequentialCommandGroup();

protected:
	SequentialCommandGroup(Vector<Command*>* commands);
	void initialize();
	void execute();
	bool isFinished();

private:
	Vector<Command*>* _commands;
	uint8_t activeCommandIdx;

	Command* activeCommand();
};
