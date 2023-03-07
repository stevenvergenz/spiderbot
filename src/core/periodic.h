#pragma once
#include <set>
#include <exception>
#include <iostream>

class Periodic
{
public:
	static void runPeriodics();
	virtual void periodic() = 0;

protected:
	Periodic();
	~Periodic();

private:
	static std::set<Periodic*> list;
};
