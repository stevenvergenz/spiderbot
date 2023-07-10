#include "commands/blinkMorse.h"

constexpr const Pattern BlinkMorseCommand::MORSE[26];

BlinkMorseCommand::BlinkMorseCommand(const char* phrase)
	: SequentialCommandGroup(phrase, stringToCommandList(phrase))
{

}

Vector<Command*>* BlinkMorseCommand::stringToCommandList(const char* phrase)
{
	int length;
	for (length = 1; phrase[length-1] != '\0'; length++) { }

	Command** buffer = new Command*[length];
	Vector<Command*>* list = new Vector<Command*>();
	list->setStorage(buffer, length, 0);

	for (const char* i = phrase; *i != '\0'; i++)
	{
		Log.infoln("Building blink command for %c", *i);
		Pattern p = isUpperCase(*i) ? MORSE[*i - 'A'] : isLowerCase(*i) ? MORSE[*i - 'a'] : ERR;
		list->push_back(new BlinkCommand(new char[2] { *i, '\0' }, p));
	}

	list->push_back(new BlinkCommand("break", BREAK));

	return list;
}
