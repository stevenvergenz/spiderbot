#include "core/ticker.h"

Ticker* Ticker::tickers[Ticker::maxTickers];
uint16_t Ticker::tickerSlots = 0;

void Ticker::schedule()
{
	for (uint8_t slot = 0; slot < Ticker::maxTickers; slot++)
	{
		uint16_t slotFlag = 1 << slot;
		if (!(Ticker::tickerSlots & slotFlag))
		{
			Ticker::tickers[slot] = this;
			tickerSlot = slot;
		}
	}
}

void Ticker::unschedule()
{
	Ticker::tickers[tickerSlot] = nullptr;
	tickerSlot = 0;
}

bool Ticker::isScheduled()
{
	return Ticker::tickers[tickerSlot] == this;
}

void Ticker::updateTickers()
{
	for (Ticker* t : Ticker::tickers)
	{
		t->tick();
	}
}
