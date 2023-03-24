#pragma once
#include <stdio.h>

#define LOW 0
#define HIGH 1
#define INPUT 0
#define OUTPUT 1

#define BIN 2
#define OCT 8
#define DEC 10
#define HEX 16

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

void pinMode(int pinIdx, int mode);
void digitalWrite(int pinIdx, int output);
bool isUpperCase(char c);
bool isLowerCase(char c);
void delay(int ms);

class SerialShim
{
public:
	void begin(int baud);
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long, int = DEC);
    size_t print(unsigned long, int = DEC);
    size_t print(double, int = 2);

    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC);
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2);
    size_t println(void);
} Serial;
