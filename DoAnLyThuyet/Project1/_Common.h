#include "Main_Function.h"

class _Common
{
public:
	static void removeScrollBar();
	static void changeFont(int);
	static void fixConsoleWindow();
	static void gotoXY(int, int);
	static void resizeConsole(int width, int height);
	static void fullscreen() {
		SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	}
	static void ClearScreen();
	static void setColor(int);
};
