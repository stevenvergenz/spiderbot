#pragma once
#include "subsystem.h"

class Command : public Periodic
{
public:
	void periodic();
	virtual void initialize();
	virtual void execute();
	virtual bool isFinished();
	virtual void end(bool isInterrupted);

protected:
	void addRequirements(...args);
};
