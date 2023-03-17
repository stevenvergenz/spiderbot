#include "commands/blinkMorse.h"

constexpr const Pattern BlinkMorseCommand::MORSE[26];

BlinkMorseCommand::BlinkMorseCommand(const char* phrase)
	: SequentialCommandGroup(stringToCommandList(phrase))
{

}

Vector<Command*>* BlinkMorseCommand::stringToCommandList(const char* phrase)
{
	int length;
	for (length = 0; phrase[length] != '\0'; length++) { }

	Command** buffer = new Command*[length];
	Vector<Command*>* list = new Vector<Command*>();
	list->setStorage(buffer, length, 0);

	for (char i = *phrase; i != '\0'; i++)
	{
		Pattern p = isUpperCase(i) ? MORSE[i - 'A'] : isLowerCase(i) ? MORSE[i - 'a'] : ERR;
		list->push_back(new BlinkCommand(p));
	}

	return list;
}
