#pragma once
#include <Vector.h>
#include "../core/sequentialCommandGroup.h"
#include "blink.h"

class BlinkMorseCommand : public SequentialCommandGroup
{
private:
	static constexpr Pattern MORSE[]
	{
		0b110,   // A
		0b10001, // B
		0b10101, // C
		0b1001,  // D
		0b10,    // E
		0b10100, // F
		0b1011,  // G
		0b10000, // H
		0b100,   // I
		0b11110, // J
		0b1101,  // K
		0b10010, // L
		0b111,   // M
		0b101,   // N
		0b1111,  // O
		0b10110, // P
		0b11011, // Q
		0b1010,  // R
		0b1000,  // S
		0b11,    // T
		0b1100,  // U
		0b11000, // V
		0b1110,  // W
		0b11001, // X
		0b11101, // Y
		0b10011  // Z
	};

	static constexpr Pattern ERR = 0x111111;

public:
	BlinkMorseCommand(char* phrase);
	~BlinkMorseCommand();

private:
	static Vector<Command*>* stringToCommandList(char* phrase);
};
