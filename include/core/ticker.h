#pragma once
#ifdef ARDUINO
#include <Arduino.h>
#else
#include <ArduinoShim.h>
#endif
#include "core/log.h"
#include "constants.h"

class Ticker
{
public:
	static void updateTickers();
	const char* name;
	virtual void tick() = 0;

	virtual void schedule();
	virtual void unschedule();
	bool isScheduled();

protected:
	Ticker(const char* name);

private:
	static constexpr uint8_t s_maxTickers = 16;
	static Ticker* s_tickers[s_maxTickers];
	static uint16_t s_tickerSlots;
	uint8_t _tickerSlot;
};
