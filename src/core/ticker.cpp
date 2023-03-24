#include "core/ticker.h"

Ticker* Ticker::s_tickers[Ticker::s_maxTickers];
uint16_t Ticker::s_tickerSlots = 0;

void Ticker::schedule()
{
	for (uint8_t slot = 0; slot < Ticker::s_maxTickers; slot++)
	{
		uint16_t slotFlag = 1 << slot;
		if (!(Ticker::s_tickerSlots & slotFlag))
		{
			Ticker::s_tickers[slot] = this;
			_tickerSlot = slot;
		}
	}
}

void Ticker::unschedule()
{
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
