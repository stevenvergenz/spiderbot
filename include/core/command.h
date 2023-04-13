#pragma once
#include <stdarg.h>
#include <ArduinoLog.h>
#include "ticker.h"

class Command;

#include "subsystem.h"

class Command : public Ticker
{
public:
	void tick();
	virtual void end(bool isInterrupted);
	virtual ~Command();

protected:
	Command(const char* name);
	virtual void initialize();
	virtual void execute();
	virtual bool isFinished() = 0;
	void addRequirements(Subsystem* req = nullptr);

private:
	bool isInitialized;
	Subsystem* requirement;
};
