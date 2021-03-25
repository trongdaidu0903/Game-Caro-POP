#include "Menu_Loading.h"
#include "_Common.h"
#include "chucaro.h"
#include "_Game.h"

Menu_Loading::Menu_Loading(int pLeft, int pTop)
{
	fstream f;
	f.open("Name.txt", ios::in);
	while (!f.eof())
	{
		string s;
		f >> s;
		SUB_savingFiles.push_back(s);
	}
	f.close();
	int size = SUB_savingFiles.size();
	if (SUB_savingFiles[size - 1] == "") SUB_savingFiles.resize(size - 1);
	_loop = true;
	_turn = 1;
	_command = -1; // Assign turn and default key
	_x = pLeft; _y = pTop;
}
int Menu_Loading::getCommand() { return _command; }
bool Menu_Loading::isContinue() { return _loop; }
char Menu_Loading::waitKey_Menu()
{
	_command = toupper(_getch());
	return _command;
}
bool Menu_Loading::checkBlank_SUB_savingFiles()
{
	for (int i = 0; i < SUB_savingFiles.size(); i++)
	{
		if (SUB_savingFiles[i] != "")
			return false;
	}
	return true;
}
void Menu_Loading::startMenu()
{
	system("cls");
	system("color 0f");
	chucaro a;
	char key;
	int k = 0;
	if (!checkBlank_SUB_savingFiles() || SUB_savingFiles.size() != 0) {
		_Common::setColor(0);
		for (int i = 0; i < SUB_savingFiles.size(); i++)
		{
			if (SUB_savingFiles[i] != "")
			{
				_Common::gotoXY(LEFT - 15, TOP * 5 + i);
				cout << i + 1 << ". " << SUB_savingFiles[i];
			}
		}
		_Common::setColor(1);
		_Common::gotoXY(LEFT_MENU - 8, TOP_MENU + 12);
		cout << "PRESS ESC TO BACK TO MENU";
		_Common::setColor(3);
		_Common::gotoXY(LEFT - 15, TOP * 5);
		cout << 0 + 1 << ". " << SUB_savingFiles[0];
	}
	else
	{
		_Common::gotoXY(LEFT - 15, TOP * 5);
		cout << "NO DATA TO LOAD";
	}

	while (true) {
		if (_kbhit()) {
			key = _getch();
			if (key) {
				_Common::gotoXY(LEFT - 15, TOP * 5);
				break;
			}
		}
		a.display_part4(k++);
		_Common::gotoXY(LEFT - 15, TOP * 5);
		Sleep(125);
	}

	//show vector SUB
	if (!checkBlank_SUB_savingFiles()) {
		_Common::setColor(0);
		for (int i = 0; i < SUB_savingFiles.size(); i++)
		{
			if (SUB_savingFiles[i] != "")
			{
				_Common::gotoXY(LEFT - 15, TOP * 5 + i);
				cout << i + 1 << ". " << SUB_savingFiles[i];
			}
		}
		_Common::setColor(1);
		_Common::gotoXY(LEFT_MENU - 8, TOP_MENU + 12);
		cout << "PRESS ESC TO BACK TO MENU";
		_Common::setColor(3);
		_Common::gotoXY(LEFT - 15, TOP * 5);
		cout << 0 + 1 << ". " << SUB_savingFiles[0];
	}
	else
	{
		_Common::gotoXY(LEFT - 15, TOP * 5);
		cout << "NO DATA TO LOAD";
	}
}
void Menu_Loading::exitMenu()
{
	system("cls");
	//Maybe save game before stopping
	_loop = false;
}
string Menu_Loading::processCheckMenu()
{
	vector <string> MAIN_savingFiles = { "sample1","sample2","sample3","sample4","sample5" };
	_Common::ClearScreen();
	string nameFile;
	nameFile = MAIN_savingFiles[_turn - 1];
	nameFile += ".txt";
	_loop = false;
	return nameFile;
}
void Menu_Loading::moveDown()
{
	if (_y < TOP * 5 + SUB_savingFiles.size() - 1)
	{
		Display_Loading(_y);
		_y += 1;
		_turn += 1;
		_Common::gotoXY(_x, _y);
		_Common::setColor(0);
		for (int i = 0; i < SUB_savingFiles.size(); i++)
		{
			if (SUB_savingFiles[i] != "")
			{
				if (SUB_savingFiles[i] != "")
				{
					_Common::gotoXY(LEFT - 15, TOP * 5 + i);
					cout << i + 1 << ". " << SUB_savingFiles[i];
				}
			}
		}
		_Common::setColor(3);
		_Common::gotoXY(LEFT - 15, TOP * 5 + _turn - 1);
		cout << _turn << ". " << SUB_savingFiles[_turn - 1];
		_Common::setColor(0);
	}
}
void Menu_Loading::moveUp()
{
	if (_y > TOP * 5)
	{
		Display_Loading(_y);
		_y -= 1;
		_turn -= 1;
		_Common::gotoXY(_x, _y);
		_Common::setColor(0);
		for (int i = 0; i < SUB_savingFiles.size(); i++)
		{
			if (SUB_savingFiles[i] != "")
			{
				_Common::gotoXY(LEFT - 15, TOP * 5 + i);
				cout << i + 1 << ". " << SUB_savingFiles[i];
			}
		}
		_Common::setColor(3);
		_Common::gotoXY(LEFT - 15, TOP * 5 + _turn - 1);
		cout << _turn << ". " << SUB_savingFiles[_turn - 1];
		_Common::setColor(0);
	}
}