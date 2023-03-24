#ifdef ARDUINO
#include <Arduino.h>
#else
#include <ArduinoShim.h>
#endif

int main()
{
	pinMode(LED_BUILTIN, OUTPUT);

	int counter = 0;
	bool lit = false;
	while (1)
	{
		if ((counter = (counter + 1) % 100000) == 0)
		{
			digitalWrite(LED_BUILTIN, (lit = !lit) ? HIGH : LOW);
		}
	}

	return 0;
}
