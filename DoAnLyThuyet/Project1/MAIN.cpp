#include "Main_Function.h"
#include "_Common.h"
#include "_Board.h"
#include "_Game.h"
#include "_Menu.h"
#include "_Point.h"
#include "chucaro.h"
#include "Menu_Loading.h"
#include "win_lose_draw.h"

int main()
{
	_Common::fixConsoleWindow();
	_Common::resizeConsole(1920, 1080);
	_Common::removeScrollBar();
	_Common::changeFont(22);
	Display_Menu();
}