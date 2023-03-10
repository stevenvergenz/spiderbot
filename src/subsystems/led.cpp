#include "led.h"

Led Led::s_inst;
Led& Led::instance()
{
	return Led::s_inst;
}


Led::Led()
{
	
}

bool Led::isLit()
{
	return false;
}

void Led::setLit(bool lit)
{

}
