#include "_Game.h"
#include "_Common.h"

_Game::_Game(int pSize, int pLeft, int pTop)
{
	_b = new _Board(pSize, pLeft, pTop);
	_loop = _turn = true;
	_command = -1; // Assign turn and default key
	_x = pLeft; _y = pTop;
	_lastx = _lasty = 0;
	_countX = _countO = 0;
	_winX = _winO = 0;
	flagRestart = 0;
}
_Game::~_Game() { delete _b; }
int _Game::getCommand() { return _command; }
bool _Game::isContinue() { return _loop; }
char _Game::waitKeyBoard()
{
	_command = toupper(_getch());
	return _command;
}
char _Game::askContinue()
{
	_Common::gotoXY(50, TOP * 8);
	//old:  _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 4
	cout << "Do you want to CONTINUE? (Y/N): ";
	return waitKeyBoard();
}
void _Game::startGame()
{
	system("cls");
	system("color 0f");
	_b->resetData(); // Setting the original data
	Display_WithBoard(0);
	subBoardCommand();
	subBoardLeft();
	subBoardRight();
	lineOut();
	_b->drawBoard(); // Draw boadPage 
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
	for (int i = LEFT - 62; i < LEFT - 18; i++)
	{
		_Common::gotoXY(i, TOP * 3); cout << " ";
		_Common::gotoXY(i, TOP * 3 + 1); cout << " ";
	}
	_Common::gotoXY(LEFT - 44, TOP * 3);
	if (flagRestart == 0) {
		_Common::setColor(1);
		cout << "X's turn!!";
	}
	_Common::gotoXY(_x, _y);
}
void _Game::lineOut()
{
	SetConsoleOutputCP(437);
	_Common::gotoXY(LEFT, TOP);
	cout << char(201);
	_Common::gotoXY(LEFT, TOP + 30);
	cout << char(200);
	_Common::gotoXY(LEFT + 60, TOP);
	cout << char(187);
	_Common::gotoXY(LEFT + 60, TOP + 30);
	cout << char(188);
	for (int i = LEFT + 1; i < LEFT + 60; i++)
	{
		_Common::gotoXY(i, TOP);
		cout << char(205);
		_Common::gotoXY(i, TOP + 30);
		cout << char(205);
	}
	for (int i = TOP + 1; i < TOP + 30; i++)
	{
		_Common::gotoXY(LEFT, i);
		cout << char(186);
		_Common::gotoXY(LEFT + 60, i);
		cout << char(186);
	}
}
void _Game::subBoardCommand()
{
	string title;
	SetConsoleOutputCP(437);
	_Common::setColor(7);
	_Common::gotoXY(LEFT - 64, TOP * 3 - 2);
	cout << char(201);
	_Common::gotoXY(LEFT - 64, TOP * 7);
	cout << char(200);
	_Common::gotoXY(LEFT - 16, TOP * 3 - 2);
	cout << char(187);
	_Common::gotoXY(LEFT - 16, TOP * 7);
	cout << char(188);
	for (int i = LEFT - 64 + 1; i < LEFT - 16; i++)
	{
		_Common::gotoXY(i, TOP * 3 - 2);
		cout << char(205);
		_Common::gotoXY(i, TOP * 7);
		cout << char(205);
	}
	for (int i = TOP * 3 - 2 + 1; i < TOP * 7; i++)
	{
		_Common::gotoXY(LEFT - 64, i);
		cout << char(186);
		_Common::gotoXY(LEFT - 16, i);
		cout << char(186);
	}
	title = " PLAYER vs. PLAYER ";
	_Common::setColor(3);
	_Common::gotoXY(LEFT - 49, TOP * 3 - 2);
	cout << title;

	_Common::gotoXY(LEFT - 52 + 4, TOP * 6);
	_Common::setColor(5);
	cout << " Turn off UNIKEY ";
	_Common::gotoXY(LEFT - 64 + 4, TOP * 7 - 2);
	_Common::setColor(6);
	cout << " W - Up   A - Left   S - Down   D - Right ";
	_Common::gotoXY(LEFT - 65 + 4, TOP * 7 - 1);
	_Common::setColor(4);
	cout << " Z - Undo   L - Save   T - Load   ESC - Exit ";
	_Common::setColor(0);
}
void _Game::subBoardLeft()
{
	SetConsoleOutputCP(437);
	_Common::gotoXY(LEFT - 70, TOP * 8);
	cout << char(201);
	_Common::gotoXY(LEFT - 70, TOP * 10);
	cout << char(200);
	_Common::gotoXY(LEFT - 45, TOP * 8);
	cout << char(187);
	_Common::gotoXY(LEFT - 45, TOP * 10);
	cout << char(188);
	for (int i = LEFT - 70 + 1; i < LEFT - 45; i++)
	{
		_Common::gotoXY(i, TOP * 8);
		cout << char(205);
		_Common::gotoXY(i, TOP * 10);
		cout << char(205);
	}
	for (int i = TOP * 8 + 1; i < TOP * 10; i++)
	{
		_Common::gotoXY(LEFT - 70, i);
		cout << char(186);
		_Common::gotoXY(LEFT - 45, i);
		cout << char(186);
	}
	_Common::setColor(3);
	_Common::gotoXY(LEFT - 70 + 1, TOP * 8);
	cout << " PLAYER 1 " << char(3) << " X ";
	_Common::setColor(1);
	_Common::gotoXY(LEFT - 61, TOP * 8 + 2);
	cout << "Move:  " << _countX << endl;
	_Common::gotoXY(LEFT - 61, TOP * 8 + 4);
	cout << "Score: " << _winX << endl;
	_Common::setColor(0);
}
void _Game::subBoardRight()
{
	SetConsoleOutputCP(437);
	_Common::gotoXY(LEFT - 35, TOP * 8);
	cout << char(201);
	_Common::gotoXY(LEFT - 35, TOP * 10);
	cout << char(200);
	_Common::gotoXY(LEFT - 10, TOP * 8);
	cout << char(187);
	_Common::gotoXY(LEFT - 10, TOP * 10);
	cout << char(188);
	for (int i = LEFT - 35 + 1; i < LEFT - 10; i++)
	{
		_Common::gotoXY(i, TOP * 8);
		cout << char(205);
		_Common::gotoXY(i, TOP * 10);
		cout << char(205);
	}
	for (int i = TOP * 8 + 1; i < TOP * 10; i++)
	{
		_Common::gotoXY(LEFT - 35, i);
		cout << char(186);
		_Common::gotoXY(LEFT - 10, i);
		cout << char(186);
	}
	_Common::setColor(3);
	_Common::gotoXY(LEFT - 35 + 1, TOP * 8);
	cout << " PLAYER 2 " << char(3) << " O ";
	_Common::setColor(2);
	_Common::gotoXY(LEFT - 26, TOP * 8 + 2);
	cout << "Move:  " << _countO << endl;
	_Common::gotoXY(LEFT - 26, TOP * 8 + 4);
	cout << "Score: " << _winO << endl;
	_Common::setColor(0);
}
void _Game::exitGame()
{
	system("cls");
	//Maybe save game before stopping
	_loop = false;
}
bool _Game::processCheckBoard()
{
	switch (_b->checkBoard(_x, _y, _turn))
	{
	case -1: {
		_countX++;
		PlaySound(L"Bonussound.wav", NULL, SND_ASYNC);
		Display_WithBoard(_x);
		_Common::gotoXY(_x, _y);
		_Common::setColor(1);
		cout << "X";

		for (int i = LEFT - 62; i < LEFT - 18; i++)
		{
			_Common::gotoXY(i, TOP * 3); cout << " ";
		}
		_Common::gotoXY(LEFT - 44, TOP * 3);
		_Common::setColor(2);
		cout << "O's turn!!";
		break;
	}
	case 1: {
		_countO++;
		PlaySound(L"Bonussound.wav", NULL, SND_ASYNC);
		Display_WithBoard(_y);
		_Common::gotoXY(_x, _y);
		_Common::setColor(2);
		cout << "O";
		for (int i = LEFT - 62; i < LEFT - 18; i++)
		{
			_Common::gotoXY(i, TOP * 3); cout << " ";
		}
		_Common::gotoXY(LEFT - 44, TOP * 3);
		_Common::setColor(1);
		cout << +"X's turn!!";
		break;
	}
	case 0: return false; // Tick the cell marked
	}
	_lastx = _x;
	_lasty = _y;
	_Common::gotoXY(_x, _y);
	return true;
}
int _Game::processFinish()
{
	_Common::setColor(1);
	_Common::gotoXY(LEFT - 61, TOP * 8 + 2);
	cout << "Move:  " << _countX << endl;
	_Common::setColor(2);
	_Common::gotoXY(LEFT - 26, TOP * 8 + 2);
	cout << "Move:  " << _countO << endl;
	_Common::setColor(0);
	int pWhoWin = _b->testBoard(_turn);
	switch (pWhoWin)
	{
	case -1:
		_winX++;
		_Common::setColor(1);
		_Common::gotoXY(LEFT - 61, TOP * 8 + 4);
		cout << "Score: " << _winX << endl;
		_countX = _countO = 0;
		Sleep(1000);
		_Common::ClearScreen();
		PlaySound(L"winner.wav", NULL, SND_ASYNC);
		Display_ForWinner(_turn);
		_Common::ClearScreen();
		Display_ForLoser(!_turn);
		break;
	case 1:
		_winO++;
		_Common::setColor(2);
		_Common::gotoXY(LEFT - 26, TOP * 8 + 4);
		cout << "Score: " << _winO << endl;
		_countX = _countO = 0;
		Sleep(1000);
		_Common::ClearScreen();
		PlaySound(L"winner.wav", NULL, SND_ASYNC);
		Display_ForWinner(_turn);
		_Common::ClearScreen();
		Display_ForLoser(!_turn);
		break;
	case 0:
		_countX = _countO = 0;
		_Common::ClearScreen();
		PlaySound(L"drawngame.wav", NULL, SND_ASYNC);
		Display_ForDraw();
		break;
	case 2:
		_turn = !_turn; // change turn if nothing happen
	}
	_Common::gotoXY(_x, _y);// Return the current position of cursor
	return pWhoWin;
}
void _Game::moveRight()
{
	if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1))
	{
		PlaySound(L"Bonussound.wav", NULL, SND_ASYNC);
		_x += 4;
		_lastx = _x;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveLeft()
{
	if (_x > _b->getXAt(0, 0))
	{
		PlaySound(L"Bonussound.wav", NULL, SND_ASYNC);
		_x -= 4; _lastx = _x;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveDown()
{
	if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1))
	{
		PlaySound(L"Bonussound.wav", NULL, SND_ASYNC);
		_y += 2; _lasty = _y;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveUp()
{
	if (_y > _b->getYAt(0, 0))
	{
		PlaySound(L"Bonussound.wav", NULL, SND_ASYNC);
		_y -= 2; _lasty = _y;
		_Common::gotoXY(_x, _y);
	}
}
string _Game::getFileToLoad()
{
	//begin
	//xử lý file
	vector <string> MAIN_savingFiles = { "sample1","sample2","sample3","sample4","sample5" };

	vector <string> SUB_savingFiles;
	fstream f;
	int i = 0;
	f.open("Name.txt", ios::in);
	while (!f.eof())
	{
		string s;
		f >> s;
		SUB_savingFiles.push_back(s);
		i++;
	}
	f.close();
	int mark = 0;
	for (int i = 0; i < SUB_savingFiles.size(); i++)
	{
		if (SUB_savingFiles[i] != "") {
			mark = 1; break;
		}
	}
	_Common::gotoXY(LEFT - 60, TOP * 4 - 1);
	if (mark == 1) {
		cout << "LIST: ";
		//show vector SUB
		for (int i = 0; i < SUB_savingFiles.size(); i++)
		{
			if (SUB_savingFiles[i] != "") {
				_Common::gotoXY(LEFT - 52, TOP * 4 - 1 + i);
				cout << i + 1 << ". " << SUB_savingFiles[i];
			}
		}
		// gõ stt file cần LOAD
		int temp;
		_Common::gotoXY(LEFT - 60, TOP * 5 + 1);
		cout << "Type no. of file: ";
		cin >> temp;
		if (temp > 6 || temp < 1)
		{
			_Common::gotoXY(LEFT - 60, TOP * 5 + 2);
			cout << "Invalid. Input again.  ";
			cin >> temp;
		}
		// update tên biến trong MAIN vector
		string nameFile;
		nameFile = MAIN_savingFiles[temp - 1];
		nameFile += ".txt";
		// end
		return nameFile;
	}
	else
	{
		cout << "NO FILE TO LOAD";
		return "";
	}
}
void _Game::processLoadInGame(string nameFile)
{
	if (nameFile != "") {
		//string nameFile = getFileToLoad();
		ifstream loadingFile;
		loadingFile.open(nameFile);
		//bat dau load
		loadingFile >> _lastx;	loadingFile >> _lasty;
		loadingFile >> _countX;	loadingFile >> _countO;
		loadingFile >> _winX;	loadingFile >> _winO;
		int loading[BOARD_SIZE][BOARD_SIZE];
		for (int i = 0; i < BOARD_SIZE; i++)
			for (int j = 0; j < BOARD_SIZE; j++)
				loadingFile >> loading[i][j];
		loadingFile.close();
		flagRestart = 1;
		startGame();
		_Common::setColor(1);
		_Common::gotoXY(LEFT - 61, TOP * 8 + 2);
		cout << "Move:  " << _countX << endl;
		_Common::gotoXY(LEFT - 61, TOP * 8 + 4);
		cout << "Score: " << _winX << endl;
		_Common::setColor(2);
		_Common::gotoXY(LEFT - 26, TOP * 8 + 2);
		cout << "Move:  " << _countO << endl;
		_Common::gotoXY(LEFT - 26, TOP * 8 + 4);
		cout << "Score: " << _winO << endl;
		_Common::gotoXY(LEFT - 44, TOP * 3);
		if (_countX > _countO)
		{
			_Common::setColor(2);
			cout << "O's turn!!";
			_turn = false;
		}
		else
		{
			_Common::setColor(1);
			cout << "X's turn!!";
			_turn = true;
		}
		_Common::setColor(0);
		_b->load(loading);
		_x = _lastx; _y = _lasty;
		_Common::gotoXY(_lastx, _lasty);
	}
	else
	{
		_Common::gotoXY(_x, _y);
	}
}
string _Game::getFileToSave()
{
	vector <string> MAIN_savingFiles = { "sample1","sample2","sample3","sample4","sample5" };
	for (int i = LEFT - 62; i < LEFT - 18; i++)
	{
		_Common::gotoXY(i, TOP * 3); cout << " ";
	}
	string nameFile;
	_Common::gotoXY(LEFT - 62, TOP * 3 + 1);
	cout << "Type name of file: ";
	cin >> nameFile;
	//xử lý file
	vector <string> SUB_savingFiles = { "","","","","" };
	ifstream f;
	int i = 0;
	f.open("Name.txt");
	while (!f.eof())
	{
		string s;
		f >> s;
		SUB_savingFiles[i] = s;
		i++;
	}

	int flag = 0;
	for (int i = 0; i < SUB_savingFiles.size(); i++)
	{
		if (SUB_savingFiles[i] == "")
		{
			SUB_savingFiles[i] = nameFile;
			nameFile = MAIN_savingFiles[i];
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		int temp;
		// nhớ chèn tọa độ để in chữ
		_Common::gotoXY(LEFT - 60, TOP * 4);
		cout << "LIST: ";
		//show vector SUB
		for (int i = 0; i < SUB_savingFiles.size(); i++)
		{
			if (SUB_savingFiles[i] != "") {
				_Common::gotoXY(LEFT - 52, TOP * 4 + i);
				cout << i + 1 << ". " << SUB_savingFiles[i];
			}
		}
		_Common::gotoXY(LEFT - 62, TOP * 4 - 1);
		cout << "No space to save. Choose file to delete. ";
		// xuat stt cac file trong SUB vector
		// nhap stt file muon xoa
		cin >> temp;
		SUB_savingFiles[temp - 1] = nameFile;
		nameFile = MAIN_savingFiles[temp - 1];
	}
	f.close();
	ofstream f_;
	f_.open("Name.txt");
	for (int i = 0; i < SUB_savingFiles.size(); i++)
	{
		f_ << endl << SUB_savingFiles[i];
	}
	f_.close();
	nameFile += ".txt";
	//xoa cac dong trong o subCommand
	for (int j = 0; j < 8; j++) {
		for (int i = LEFT - 62; i < LEFT - 18; i++)
		{
			_Common::gotoXY(i, TOP * 3 + 1 + j); cout << " ";
		}
	}
	return nameFile;
}
void _Game::processSave(string nameFile)
{
	ofstream savingFile;
	savingFile.open(nameFile);

	//buoc di, thang thua, ten ng choi
	savingFile << _lastx << endl << _lasty << endl;
	savingFile << _countX << endl << _countO << endl;
	savingFile << _winX << endl << _winO << endl;
	int saving[BOARD_SIZE][BOARD_SIZE];
	_b->save(saving);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			savingFile << saving[i][j] << " ";
		savingFile << endl;
	}
	savingFile.close();
	_Common::gotoXY(LEFT - 62, TOP * 4);
	if (nameFile != "ContinueFile.txt") {
		cout << "Do you wanna EXIT? (Y/N) ";
		waitKeyBoard();
		if (getCommand() == 'n' || getCommand() == 'N')
		{
			cout << "NO";
			Sleep(1000);
			for (int i = LEFT - 62; i < LEFT - 18; i++)
			{
				_Common::gotoXY(i, TOP * 4 - 1);
				cout << " ";
				_Common::gotoXY(i, TOP * 4);
				cout << " ";
			}
			_Common::gotoXY(LEFT - 44, TOP * 3);
			if (_countX > _countO)
			{
				_Common::setColor(2);
				cout << "O's turn!!";
				_turn = false;
			}
			else
			{
				_Common::setColor(1);
				cout << "X's turn!!";
				_turn = true;
			}
			_Common::gotoXY(_lastx, _lasty);
		}
		else
		{
			cout << "YES";
			Sleep(1000);
			exitGame();
		}
	}
}
void _Game::processUndo()
{
	string name; int num_Color;
	if (_turn) { _countO--; num_Color = 2; name = "X"; }
	else { _countX--; num_Color = 1; name = "O"; }
	_Common::setColor(1);
	_Common::gotoXY(LEFT - 61, TOP * 8 + 2);
	cout << "Move:  " << _countX << endl;
	_Common::setColor(2);
	_Common::gotoXY(LEFT - 26, TOP * 8 + 2);
	cout << "Move:  " << _countO << endl;
	for (int i = LEFT - 62; i < LEFT - 18; i++)
	{
		_Common::gotoXY(i, TOP * 3); cout << " ";
	}
	_Common::gotoXY(LEFT - 44, TOP * 3);
	_Common::setColor(num_Color);
	cout << name + "'s turn!!";
	_Common::setColor(0);
	_b->undo(_lastx, _lasty);
	_Common::gotoXY(_lastx, _lasty);
	cout << " ";
	_x = _lastx;
	_y = _lasty;
	_Common::gotoXY(_x, _y);
	_turn = !_turn;
}