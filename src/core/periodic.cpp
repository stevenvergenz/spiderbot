#include "periodic.h"

std::set<Periodic*> Periodic::list;

Periodic::Periodic()
{
	Periodic::list.insert(this);
}

Periodic::~Periodic()
{
	Periodic::list.erase(this);
}

void Periodic::runPeriodics()
{
	for (Periodic* p : Periodic::list)
	{
		try
		{
			p->periodic();
		}
		catch (std::exception& ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
}
