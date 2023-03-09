#include "core/ticker.h"

int main(int argc, char **argv)
{
	for (;;)
	{
		Ticker::updateTickers();
	}

	return 0;
}
