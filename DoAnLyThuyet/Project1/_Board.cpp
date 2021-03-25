#include "_Board.h"
#include "_Common.h"

int _Board::getSize() { return _size; }
int _Board::getLeft() { return _left; }
int _Board::getTop() { return _top; }
int _Board::getXAt(int i, int j) { return _pArr[i][j].getX(); }
int _Board::getYAt(int i, int j) { return _pArr[i][j].getY(); }
_Board::_Board(int pSize, int pX, int pY)
{
	_size = pSize;
	_left = pX;
	_top = pY;
	_pArr = new _Point * [pSize];
	for (int i = 0; i < pSize; i++) _pArr[i] = new _Point[pSize];
}
_Board::~_Board()
{
	for (int i = 0; i < _size; i++) delete[] _pArr[i];
	delete[] _pArr;
}
void _Board::resetData()
{
	if (_size == 0) return; // Firstly calling constructor before calling resetData
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_pArr[i][j].setX(4 * j + _left + 2); // x-value of boardgame
			_pArr[i][j].setY(2 * i + _top + 1); // y-value of boardgame
			_pArr[i][j].setCheck(0);
		}
	}
}
void _Board::drawBoard()
{
	if (_pArr == NULL) return; // firstly call constructor
	for (int i = 1; i <= _size - 1; i++) {
		for (int j = 1; j <= _size - 1; j++) {
			_Common::gotoXY(_left + 4 * i - 3, _top + 2 * j);
			cout << char(196) << char(196) << char(196) << char(179) << char(196) << char(196) << char(196);
			_Common::gotoXY(_left + 4 * i, _top + j + _top + j - 2);
			cout << char(179);
		}
		_Common::gotoXY(_left + 4 * i, _top + 1);
		cout << char(179);
	}
	_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());//move to the st cell
}
int _Board::checkBoard(int pX, int pY, bool pTurn)
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
			{
				if (pTurn) _pArr[i][j].setCheck(-1);// If current turn is true: c = -1
				else _pArr[i][j].setCheck(1);// If current turn is false: c = 1
				return _pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}
void _Board::undo(int pX, int pY)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY)
			{
				_pArr[i][j].setCheck(0);
			}
		}
	}
}
void _Board::save(int savingA[][BOARD_SIZE])
{
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			savingA[i][j] = _pArr[i][j].getCheck();
		}
	}
}
void _Board::load(int loadingA[][BOARD_SIZE])
{
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			_pArr[i][j].setCheck(loadingA[i][j]);
			_Common::gotoXY(_pArr[i][j].getX(), _pArr[i][j].getY());
			switch (_pArr[i][j].getCheck())
			{
			case -1:
				_Common::setColor(1);
				cout << "X";
				break;
			case 1:
				_Common::setColor(2);
				cout << "O";
				break;
			case 0: continue;
			}
		}
		cout << endl;
	}
}
int _Board::testBoard(bool pTurn) // Luat khong chan 2 dau
{
	int check;
	if (pTurn) check = -1;
	else check = 1;
	int count_draw = 0;
	for (int i = 0; i < _size; i++) 
	{
		for (int j = 0; j < _size; j++) 
		{
			if (_pArr[i][j].getCheck() == 0) count_draw++;
		}
	}
	if (count_draw == 0) return 0;

	for (int i = 0; i < _size; i++) 
	{
		for (int j = 0; j < _size; j++)
		{
			if (i < _size - 4 && j < _size - 4)
			{
				if (_pArr[i][j].getCheck() == _pArr[i + 1][j].getCheck() && _pArr[i][j].getCheck() == _pArr[i + 2][j].getCheck()
					&& _pArr[i][j].getCheck() == _pArr[i + 3][j].getCheck() && _pArr[i][j].getCheck() == _pArr[i + 4][j].getCheck()
					&& _pArr[i][j].getCheck() == check)
					return check;

				if (_pArr[i][j].getCheck() == _pArr[i][j + 1].getCheck() && _pArr[i][j].getCheck() == _pArr[i][j + 2].getCheck()
					&& _pArr[i][j].getCheck() == _pArr[i][j + 3].getCheck() && _pArr[i][j].getCheck() == _pArr[i][j + 4].getCheck()
					&& _pArr[i][j].getCheck() == check)
					return check;

				if (_pArr[i][j].getCheck() == _pArr[i + 1][j + 1].getCheck() && _pArr[i][j].getCheck() == _pArr[i + 2][j + 2].getCheck()
					&& _pArr[i][j].getCheck() == _pArr[i + 3][j + 3].getCheck() && _pArr[i][j].getCheck() == _pArr[i + 4][j + 4].getCheck()
					&& _pArr[i][j].getCheck() == check)
					return check;
			}

			if (i >= _size - 4 && j < _size - 4)
			{
				if (_pArr[i][j].getCheck() == _pArr[i][j + 1].getCheck() && _pArr[i][j].getCheck() == _pArr[i][j + 2].getCheck()
					&& _pArr[i][j].getCheck() == _pArr[i][j + 3].getCheck() && _pArr[i][j].getCheck() == _pArr[i][j + 4].getCheck()
					&& _pArr[i][j].getCheck() == check)
					return check;
			}

			if (i < _size - 4 && j >= _size - 4)
			{
				if (_pArr[i][j].getCheck() == _pArr[i + 1][j].getCheck() && _pArr[i][j].getCheck() == _pArr[i + 2][j].getCheck()
					&& _pArr[i][j].getCheck() == _pArr[i + 3][j].getCheck() && _pArr[i][j].getCheck() == _pArr[i + 4][j].getCheck()
					&& _pArr[i][j].getCheck() == check)
					return check;
			}

			if (i > 3 && j < _size - 4)
			{
				if (_pArr[i][j].getCheck() == _pArr[i - 1][j + 1].getCheck() && _pArr[i][j].getCheck() == _pArr[i - 2][j + 2].getCheck()
					&& _pArr[i][j].getCheck() == _pArr[i - 3][j + 3].getCheck() && _pArr[i][j].getCheck() == _pArr[i - 4][j + 4].getCheck()
					&& _pArr[i][j].getCheck() == check)
					return check;
			}
		}
	}
	return 2;
}