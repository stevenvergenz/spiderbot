#pragma once
#include "../constants.h"

class Ticker
{
public:
	static void updateTickers();
	virtual void tick() = 0;

	void schedule();
	void unschedule();
	bool isScheduled();

private:
	static const uint8 maxTickers = 16;
	static Ticker* tickers[maxTickers];
	static uint16 tickerSlots;
	uint8 tickerSlot;
};
