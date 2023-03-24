#include "core/ticker.h"

Ticker* Ticker::s_tickers[Ticker::s_maxTickers];
uint16_t Ticker::s_tickerSlots = 0;

Ticker::Ticker(const char* name)
{
	this->name = name;
}

void Ticker::schedule()
{
	Log::trace("Ticker.schedule");
	for (uint8_t slot = 0; slot < Ticker::s_maxTickers; slot++)
	{
		uint16_t slotFlag = 1 << slot;
		if (!(Ticker::s_tickerSlots & slotFlag))
		{
			//Serial.print("Assigning new ticker ");
			//Serial.print(name);
			//Serial.print(" to slot ");
			//Serial.println(slot);
			Ticker::s_tickers[slot] = this;
			_tickerSlot = slot;
			break;
		}
	}
}

void Ticker::unschedule()
{
	Log::trace("Ticker.unschedule");
	Ticker::s_tickers[_tickerSlot] = nullptr;
	_tickerSlot = 0;
}

bool Ticker::isScheduled()
{
	return Ticker::s_tickers[_tickerSlot] == this;
}

void Ticker::updateTickers()
{
	for (Ticker* t : Ticker::s_tickers)
	{
		if (t != nullptr)
		{
			t->tick();
		}
	}
}
