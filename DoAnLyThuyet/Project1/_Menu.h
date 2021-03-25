#include "Main_Function.h"

class _Menu
{
private:
	int _turn;// turn: true for the st player and false for the nd player
	int _x, _y; // current position of cursor
	int _command; // input-key from the players
	bool _loop; // decision bool variable to exit game or not
public:

	_Menu(int, int);
	~_Menu() { }
	int getCommand();
	bool isContinue();
	char waitKey_Menu(); // Receiving keyboard from players
	void startMenu(); // Function to start the game
	void exitMenu(); // Function to exit the game
	bool processCheckMenu();
	void moveUp();
	void moveDown();
	void loadingBar();
};
