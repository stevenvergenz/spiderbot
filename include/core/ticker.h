#pragma once
#include <Arduino.h>
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
	static const uint8_t maxTickers = 16;
	static Ticker* tickers[maxTickers];
	static uint16_t tickerSlots;
	uint8_t tickerSlot;
};
