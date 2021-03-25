#include "_Menu.h"
#include "_Common.h"
#include "_Game.h"

void _Menu::loadingBar()
{
	system("cls");
	Sleep(3000);
	_Common::changeFont(32);
	_Common::gotoXY(LEFT_LOADING, TOP_MENU - 6);
	cout << char(218);
	_Common::gotoXY(LEFT_LOADING, TOP_MENU - 4);
	cout << char(192);
	_Common::gotoXY(LEFT_LOADING * 2 + 9, TOP_MENU - 6);
	cout << char(191);
	_Common::gotoXY(LEFT_LOADING * 2 + 9, TOP_MENU - 4);
	cout << char(217);
	_Common::gotoXY(LEFT_LOADING, TOP_MENU - 5);
	cout << char(179);
	_Common::gotoXY(LEFT_LOADING * 2 + 9, TOP_MENU - 5);
	cout << char(179);
	_Common::setColor(3);

	int j = -6;
	for (int i = LEFT_LOADING + 1; i < LEFT_LOADING + 39; i++)
	{
		_Common::gotoXY(i, TOP_MENU - 5);
		cout << char(219);
		_Common::gotoXY(LEFT_LOADING + 19, TOP_MENU - 8);
		if (j >= 100) cout << "100 %";
		else if (j < 0) cout << "0 %";
		else cout << " " << j << " %";
		j += 3;
		Sleep(125);
	}
	Sleep(1500);
	_Common::changeFont(22);
}
_Menu::_Menu(int pLeft, int pTop)
{
	_loop = true;
	_turn = 1;
	_command = -1; // Assign turn and default key
	_x = pLeft; _y = pTop;
}
int _Menu::getCommand() { return _command; }
bool _Menu::isContinue() { return _loop; }
char _Menu::waitKey_Menu()
{
	_command = toupper(_getch());
	return _command;
}
void _Menu::startMenu()
{
	PlaySound(L"Bonneton.wav", NULL, SND_ASYNC | SND_LOOP);
	system("cls");
	system("color 0f");
	_Common::setColor(3);
	_Common::gotoXY(LEFT_MENU, TOP_MENU);
	cout << "NEW GAME";
	_Common::setColor(0);
	_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
	cout << "CONTINUE GAME";
	_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
	cout << "LOAD GAME";
	_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
	cout << "INSTRUCTION";
	_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
	cout << "ABOUT";
	_Common::setColor(1);
	_Common::gotoXY(LEFT_MENU - 1, TOP_MENU + 12);
	cout << "PRESS ESC TO EXIT";
	_Common::gotoXY(LEFT_MENU, TOP_MENU);
	Display_();
}
void _Menu::exitMenu()
{
	system("cls");
	//Maybe save game before stopping
	_loop = false;
}
bool _Menu::processCheckMenu()
{
	_Common::ClearScreen();
	switch (this->_turn)
	{
	case 1: {
		_Game g(BOARD_SIZE, LEFT, TOP);
		g.startGame();
		while (g.isContinue()) {
			g.waitKeyBoard();
			if (g.getCommand() == 27)
			{
				for (int i = LEFT - 62; i < LEFT - 18; i++)
				{
					_Common::gotoXY(i, TOP * 3); cout << " ";
				}
				_Common::gotoXY(LEFT - 62, TOP * 4 - 1);
				cout << "Do you wanna EXIT? (Y/N) ";
				g.waitKeyBoard();
				if (g.getCommand() == 'n' || g.getCommand() == 'N')
				{
					cout << "NO";
					Sleep(1000);
					_Common::gotoXY(g._lastX_return(), g._lastY_return());
				}
				else
				{
					cout << "YES";
					Sleep(1000);
					g.processSave("ContinueFile.txt");
					g.exitGame();
				}
			}
			else {
				switch (g.getCommand()) {
				case 'A': case 75:
					g.moveLeft();
					break;
				case 'W': case 72:
					g.moveUp();
					break;
				case 'S': case 80:
					g.moveDown();
					break;
				case 'D': case 77:
					g.moveRight();
					break;
				case 'Z':
					g.processUndo();
					break;
				case 'L':
					g.processSave(g.getFileToSave());
					break;
				case 'T':
					g.processLoadInGame(g.getFileToLoad());
					break;
				case 'B':
					g.processSave("ContinueFile.txt");
					Display_Menu();
					break;
				case 13:
					//Mark the board, then check and process win/lose/draw/continue
					if (g.processCheckBoard()) {
						switch (g.processFinish()) {
						case -1: case 1: case 0:
							if (g.askContinue() == 'Y' || g.askContinue() == 'y')
							{
								cout << "YES";
								Sleep(1000);
								g.flagRestart = 1;
								g.startGame();
							}
							else
							{
								cout << "NO";
								Sleep(1000);
								g.exitGame();
							}
						}
					}
				}
			}
		}
		_loop = false;
		break;
	}
	case 2: {
		_Game g(BOARD_SIZE, LEFT, TOP);
		g.processLoadInGame("ContinueFile.txt");
		while (g.isContinue()) {
			g.waitKeyBoard();
			if (g.getCommand() == 27)
			{
				for (int i = LEFT - 62; i < LEFT - 18; i++)
				{
					_Common::gotoXY(i, TOP * 3); cout << " ";
				}
				_Common::gotoXY(LEFT - 62, TOP * 4 - 1);
				cout << "Do you wanna EXIT? (Y/N) ";
				g.waitKeyBoard();
				if (g.getCommand() == 'n' || g.getCommand() == 'N')
				{
					cout << "NO";
					Sleep(1000);
					_Common::gotoXY(g._lastX_return(), g._lastY_return());
				}
				else
				{
					cout << "YES";
					Sleep(1000);
					g.processSave("ContinueFile.txt");
					g.exitGame();
				}
			}
			else {
				switch (g.getCommand()) {
				case 'A': case 75:
					g.moveLeft();
					break;
				case 'W': case 72:
					g.moveUp();
					break;
				case 'S': case 80:
					g.moveDown();
					break;
				case 'D': case 77:
					g.moveRight();
					break;
				case 'Z':
					g.processUndo();
					break;
				case 'L':
					g.processSave(g.getFileToSave());
					break;
				case 'T':
					g.processLoadInGame(g.getFileToLoad());
					break;
				case 'B':
					g.processSave("ContinueFile.txt");
					Display_Menu();
					break;
				case 13:
					//Mark the board, then check and process win/lose/draw/continue
					if (g.processCheckBoard()) {
						switch (g.processFinish()) {
						case -1: case 1: case 0:
							if (g.askContinue() == 'Y' || g.askContinue() == 'y')
							{
								cout << "YES";
								Sleep(1000);
								g.flagRestart = 1;
								g.startGame();
							}
							else
							{
								cout << "NO";
								Sleep(1000);
								g.exitGame();
							}
						}
					}
				}
			}
		}
		_loop = false;
		break;
	}
	case 3: {
		_Game g(BOARD_SIZE, LEFT, TOP);
		g.processLoadInGame(Display_Menu_Loading());
		while (g.isContinue()) {
			g.waitKeyBoard();
			if (g.getCommand() == 27)
			{
				for (int i = LEFT - 62; i < LEFT - 18; i++)
				{
					_Common::gotoXY(i, TOP * 3); cout << " ";
				}
				_Common::gotoXY(LEFT - 62, TOP * 4 - 1);
				cout << "Do you wanna EXIT? (Y/N) ";
				g.waitKeyBoard();
				if (g.getCommand() == 'n' || g.getCommand() == 'N')
				{
					cout << "NO";
					Sleep(1000);
					_Common::gotoXY(g._lastX_return(), g._lastY_return());
				}
				else
				{
					cout << "YES";
					Sleep(1000);
					g.processSave("ContinueFile.txt");
					g.exitGame();
				}
			}
			else {
				switch (g.getCommand()) {
				case 'A': case 75:
					g.moveLeft();
					break;
				case 'W': case 72:
					g.moveUp();
					break;
				case 'S': case 80:
					g.moveDown();
					break;
				case 'D': case 77:
					g.moveRight();
					break;
				case 'Z':
					g.processUndo();
					break;
				case 'L':
					g.processSave(g.getFileToSave());
					break;
				case 'T':
					g.processLoadInGame(g.getFileToLoad());
					break;
				case 'B':
					g.processSave("ContinueFile.txt");
					Display_Menu();
					break;
				case 13:
					//Mark the board, then check and process win/lose/draw/continue
					if (g.processCheckBoard()) {
						switch (g.processFinish()) {
						case -1: case 1: case 0:
							if (g.askContinue() == 'Y' || g.askContinue() == 'y')
							{
								cout << "YES";
								Sleep(1000);
								g.flagRestart = 1;
								g.startGame();
							}
							else
							{
								cout << "NO";
								Sleep(1000);
								g.exitGame();
							}
						}
					}
				}
			}
		}
		_loop = false;
		break;
	}
	case 4: {
		Display_WithInstruction();
		_loop = false;
		break;
	}
	case 5: {
		Display_WithAbout();
		_loop = false;
		break;
	}
	case 0: return false; // Tick the cell marked
	}
	return true;
}
void _Menu::moveDown()
{
	if (_y < TOP_MENU + 4)
	{
		_y += 1;
		_turn += 1;
		_Common::gotoXY(_x, _y);
		switch (_y)
		{
		case TOP_MENU:
			_Common::setColor(3);
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			cout << "NEW GAME";
			_Common::setColor(0);
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			cout << "CONTINUE GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			cout << "LOAD GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			cout << "INSTRUCTION";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			cout << "ABOUT";
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			break;
		case TOP_MENU + 1:
			_Common::setColor(3);
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			cout << "CONTINUE GAME";
			_Common::setColor(0);
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			cout << "NEW GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			cout << "LOAD GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			cout << "INSTRUCTION";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			cout << "ABOUT";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			break;
		case TOP_MENU + 2:
			_Common::setColor(3);
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			cout << "LOAD GAME";
			_Common::setColor(0);
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			cout << "NEW GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			cout << "CONTINUE GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			cout << "INSTRUCTION";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			cout << "ABOUT";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			break;
		case TOP_MENU + 3:
			_Common::setColor(3);
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			cout << "INSTRUCTION";
			_Common::setColor(0);
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			cout << "NEW GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			cout << "CONTINUE GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			cout << "LOAD GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			cout << "ABOUT";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			break;
		case TOP_MENU + 4:
			_Common::setColor(3);
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			cout << "ABOUT";
			_Common::setColor(0);
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			cout << "NEW GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			cout << "CONTINUE GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			cout << "LOAD GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			cout << "INSTRUCTION";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			break;
		}
	}
}
void _Menu::moveUp()
{
	if (_y > TOP_MENU)
	{
		_y -= 1;
		_turn -= 1;
		_Common::gotoXY(_x, _y);
		switch (_y)
		{
		case TOP_MENU:
			_Common::setColor(3);
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			cout << "NEW GAME";
			_Common::setColor(0);
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			cout << "CONTINUE GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			cout << "LOAD GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			cout << "INSTRUCTION";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			cout << "ABOUT";
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			break;
		case TOP_MENU + 1:
			_Common::setColor(3);
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			cout << "CONTINUE GAME";
			_Common::setColor(0);
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			cout << "NEW GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			cout << "LOAD GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			cout << "INSTRUCTION";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			cout << "ABOUT";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			break;
		case TOP_MENU + 2:
			_Common::setColor(3);
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			cout << "LOAD GAME";
			_Common::setColor(0);
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			cout << "NEW GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			cout << "CONTINUE GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			cout << "INSTRUCTION";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			cout << "ABOUT";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			break;
		case TOP_MENU + 3:
			_Common::setColor(3);
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			cout << "INSTRUCTION";
			_Common::setColor(0);
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			cout << "NEW GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			cout << "CONTINUE GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			cout << "LOAD GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			cout << "ABOUT";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			break;
		case TOP_MENU + 4:
			_Common::setColor(3);
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			cout << "ABOUT";
			_Common::setColor(0);
			_Common::gotoXY(LEFT_MENU, TOP_MENU);
			cout << "NEW GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 1);
			cout << "CONTINUE GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 2);
			cout << "LOAD GAME";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 3);
			cout << "INSTRUCTION";
			_Common::gotoXY(LEFT_MENU, TOP_MENU + 4);
			break;
		}
	}
}