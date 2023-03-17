#include "subsystems/led.h"

Led Led::s_inst;
Led& Led::instance()
{
	return Led::s_inst;
}


Led::Led()
{
	pinMode(Constants::LED_PIN, OUTPUT);
	_isLit = false;
}

bool Led::isLit()
{
	return _isLit;
}

void Led::setLit(bool lit)
{
	_isLit = lit;
	digitalWrite(Constants::LED_PIN, _isLit ? HIGH : LOW);
}
