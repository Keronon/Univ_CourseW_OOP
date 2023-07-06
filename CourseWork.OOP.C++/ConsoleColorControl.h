#ifndef CONSOLECOLORCONTROL_H
#define CONSOLECOLORCONTROL_H

#include "Core.h"

class ConsoleColorControl
{
protected:
	enum Colors { BLACK = 0, SAPPHIRINE, GREEN, BLUE, RED, VIOLET, YELLOW, WHITE, GRAY, LIGHT_SAPPHIRINE, LIGHT_GREEN, LIGHT_BLUE, LIGHT_RED, LIGHT_VIOLET, LIGHT_YELLOW, LIGHT_WHITE };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD basicConsoleAttr;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	void setConsoleColor(Colors background_c, Colors text_c)
	{
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		basicConsoleAttr = csbi.wAttributes;

		SetConsoleTextAttribute(hConsole, (WORD)((background_c << 4) | text_c));
	}

	void setDefaultConsoleColor()
	{
		SetConsoleTextAttribute(hConsole, basicConsoleAttr);
	}
};

#endif