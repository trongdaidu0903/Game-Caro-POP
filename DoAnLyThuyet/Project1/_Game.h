#include "Main_Function.h"
#include "_Board.h"

class _Game
{
private:
	_Board* _b;// a board game
	bool _turn;// turn: true for the st player and false for the nd player
	int _x, _y; // current position of cursor
	int _lastx, _lasty;// last position played
	int _command; // input-key from the players
	int _countX, _countO;
	int _winX, _winO;
	bool _loop; // decision bool variable to exit game or not
public:
	int flagRestart;
	_Game(int, int, int);
	~_Game();
	int getCommand();
	bool isContinue();
	char waitKeyBoard(); // Receiving keyboard from players
	char askContinue();
	void startGame(); // Function to start the game
	void exitGame(); // Function to exit the game
	int processFinish();
	bool processCheckBoard();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void processUndo();
	void processLoadInGame(string);
	void processSave(string);
	void subBoardLeft();
	void subBoardRight();
	void subBoardCommand();
	void lineOut();
	string getFileToLoad();
	string getFileToSave();
	int _lastX_return() { return _lastx; }
	int _lastY_return() { return _lasty; }
};
