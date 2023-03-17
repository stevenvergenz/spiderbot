#pragma once
#include <Vector.h>
#include "command.h"

class SequentialCommandGroup : public Command
{
public:
	void end(bool interrupted);

protected:
	SequentialCommandGroup(Vector<Command*>* commands);
	~SequentialCommandGroup();
	void initialize();
	void execute();
	bool isFinished();

private:
	Vector<Command*>* _commands;
	uint8_t activeCommandIdx;

	Command* activeCommand();
};
