#include "Main_Function.h"
#include "_Common.h"
#include "_Board.h"
#include "_Game.h"
#include "_Menu.h"
#include "_Point.h"
#include "chucaro.h"
#include "Menu_Loading.h"
#include "win_lose_draw.h"

string Space(int x)
{
	string begin;
	for (int i = 1; i <= x; i++) begin += " ";
	return begin;
}
string Charac(int x, int times)
{
	string begin;
	for (int i = 1; i <= times; i++)	begin += char(x);
	return begin;
}
void changecolor(int n)
{
	HANDLE hcc;
	hcc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcc, n);
}


void Display_ForDraw()
{
	win_lose_draw a;
	char key;
	int k = 0;
	for (int i = 0; i < 40; i++) {
		if (_kbhit()) {
			key = _getch();
			if (key != 13) {
				break;
			}
		}
		a.Display_Drawn(k++);
		Sleep(150);
		//_Common::ClearScreen();
	}
}
void Display_ForLoser(bool flag)
{
	win_lose_draw a;
	char key;
	int k = 0;
	for (int i = 0; i < 40; i++) {
		if (_kbhit()) {
			key = _getch();
			if (key != 13) {
				break;
			}
		}
		if (flag) a.Display_XIS(k++);
		else a.Display_OIS(k++);
		a.Display_Loser(k++);
		Sleep(150);
	}
}
void Display_ForWinner(bool flag)
{
	win_lose_draw a;
	char key;
	int k = 0;
	for (int i = 0; i < 40; i++) {
		if (_kbhit()) {
			key = _getch();
			if (key != 13) {
				break;
			}
		}
		if (flag) a.Display_XIS(k++);
		else a.Display_OIS(k++);
		a.Display_Winner(k++);
		Sleep(150);
		//_Common::ClearScreen();
	}
}


void Display_()
{
	chucaro a;
	char key;
	int k = 0;
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
	while (true) {
		if (_kbhit()) {
			key = _getch();
			if (key != 13) {
				_Common::gotoXY(LEFT_MENU, TOP_MENU);
				break;
			}
		}
		a.display_part1(k++);
		_Common::ClearScreen();
		a.display_part2(k++);
	}
}
void Display_WithBoard(int k)
{
	chucaro a;
	a.display_part3(k++);
}
void Display_Loading(int k)
{
	chucaro a;
	a.display_part4(k++);
}

void Display_Menu()
{
	_Menu menu(LEFT_MENU, TOP_MENU);
	menu.loadingBar();
	menu.startMenu();
	while (menu.isContinue()) {
		menu.waitKey_Menu();
		switch (menu.getCommand()) {
		case 72: case 'W':
			menu.moveUp();
			break;
		case 80: case 'S':
			menu.moveDown();
			break;
		case 13:
			menu.processCheckMenu();
			break;
		case 27:
			menu.exitMenu();
			break;
		}
	}
}
void Display_WithInstruction()
{
	chucaro a;
	char key;
	int k = 0;
	_Common::setColor(5);
	_Common::gotoXY(LEFT_MENU - 20, TOP_MENU - 9);
	cout << "--Size: " << BOARD_SIZE << "x" << BOARD_SIZE << ".";
	_Common::setColor(6);
	_Common::gotoXY(LEFT_MENU - 20, TOP_MENU - 7);
	cout << "--Comply with the basic rules of normal CARO GAME.";
	_Common::setColor(3);
	_Common::gotoXY(LEFT_MENU - 20, TOP_MENU - 5);
	cout << "--The winner is the first one has 5 consecutive boxes are checked.";
	_Common::setColor(4);
	_Common::gotoXY(LEFT_MENU - 20, TOP_MENU - 3);
	cout << "--Use W - up, A - left, S - down or D - right to move.";
	_Common::setColor(5);
	_Common::gotoXY(LEFT_MENU - 20, TOP_MENU - 1);
	cout << "--If all boxes in the BOARD are checked, the game ends in a draw.";
	_Common::setColor(6);
	_Common::gotoXY(LEFT_MENU - 20, TOP_MENU + 1);
	cout << "--Turn off Unikey before playing games.";
	_Common::setColor(4);
	_Common::gotoXY(LEFT_MENU, TOP_MENU + 10);
	cout << "WISH YOU LUCK!!";
	_Common::setColor(1);
	_Common::gotoXY(LEFT_MENU - 5, TOP_MENU + 12);
	cout << "PRESS ESC TO BACK TO MENU";
	_Common::setColor(0);
	while (true) {
		if (_kbhit()) {
			key = _getch();
			if (key == 27) {
				Display_Menu();
				break;
			}
		}
		a.display_part5(k++);
		Sleep(100);
	}
}
void Display_WithAbout()
{
	chucaro a;
	char key;
	int k = 0;
	_Common::gotoXY(LEFT_MENU - 7, TOP_MENU - 8);
	_Common::setColor(3);
	cout << "UNIVERSITY OF SCIENCE - VNUHCM";
	_Common::gotoXY(LEFT_MENU - 17, TOP_MENU - 6);
	_Common::setColor(1);
	cout << "CARO PROJECT, instructed by teacher Truong Toan Thinh";
	_Common::setColor(2);
	_Common::gotoXY(LEFT_MENU - 5, TOP_MENU - 2);
	cout << "19127216 - Dang Hoan My";
	_Common::gotoXY(LEFT_MENU - 5, TOP_MENU);
	cout << "19127237 - Truong Minh Nhut";
	_Common::gotoXY(LEFT_MENU - 5, TOP_MENU + 2);
	cout << "19127510 - Huynh Trong Phuc";
	_Common::setColor(4);
	_Common::gotoXY(LEFT_MENU, TOP_MENU + 10);
	cout << "WISH YOU LUCK!!";
	_Common::gotoXY(LEFT_MENU + 4, TOP_MENU - 4);
	_Common::setColor(5);
	cout << "19CLC3";
	_Common::setColor(1);
	_Common::gotoXY(LEFT_MENU - 5, TOP_MENU + 12);
	cout << "PRESS ESC TO BACK TO MENU";
	_Common::setColor(0);
	while (true) {
		if (_kbhit()) {
			key = _getch();
			if (key == 27) {
				Display_Menu();
				break;
			}
		}
		a.display_part6(k++);
		Sleep(125);
	}
}
string Display_Menu_Loading()
{
	string name;
	Menu_Loading menu(LEFT - 15, TOP * 5);
	menu.startMenu();
	while (menu.isContinue()) {
		menu.waitKey_Menu();
		switch (menu.getCommand()) {
		case 72: case 'W':
			menu.moveUp();
			break;
		case 80: case 'S':
			menu.moveDown();
			break;
		case 13:
			name = menu.processCheckMenu();
			break;
		case 27:
			menu.exitMenu();
			Display_Menu();
			break;
		}
	}
	return name;
}