#include <cstdlib>
#include <csignal>
#include <iostream>
#include "robot.h"
#include "core/periodic.h"

void handle_sigint(int signal)
{
	std::cout << "Received interrupt signal, exiting." << std::endl;
	exit(0);
}

int main(int argc, char **argv)
{
	// set up interrupt handling
	signal(SIGINT, handle_sigint);

	for (;;)
	{
		Periodic::runPeriodics();
	}

	return 0;
}
