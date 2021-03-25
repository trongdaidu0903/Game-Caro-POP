#include "_Point.h"
#pragma once
#include "Main_Function.h"

class _Board
{
private:
	int _size;
	int _left, _top;
	_Point** _pArr;
public:
	_Board(int, int, int);
	~_Board();
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	int testBoard(bool);
	void undo(int, int);
	void save(int[][BOARD_SIZE]);
	void load(int[][BOARD_SIZE]);
};
