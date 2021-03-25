#include "chucaro.h"
#include "_Common.h"

chucaro::chucaro()
{
	sample.push_back("       ____________        ____________         _____________        _____________                                ");
	sample.push_back("      /   ________/|      /  _______ \\ \\       /  ________  /|      /  ________   |                             ");
	sample.push_back("     /  /|_______|/      /  / /    /  / /     /  /|______/ / /     /  /|_____ /  /|                               ");
	sample.push_back("    /  / /              /  /_/____/  / /     /  __   _____/ /     /  / /     /  / /                               ");
	sample.push_back("   /  / /              /    ____    / /     /  /  \\  \\____|/     /  / /     /  / /                              ");
	sample.push_back("  /  /_/_______       /  / /    /  / /     /  / /\\ \\  \\         /  /_/_____/  / /                              ");
	sample.push_back(" /____________/|     /__/ /    /__/ /     /__/ /  \\ \\  \\       /_____________/ /                               ");
	sample.push_back("|____________|/      |__|/    |__|_/      |__|/    \\_|__|      |_____________|/                                  ");

	sample.push_back(" ____________       ______________           _____________         _____________                                ");
	sample.push_back("|\\   ________\\     / /  ________  \\		| \\   _______ \\       | \\   ______  \\                           ");
	sample.push_back("\\ \\  \\_______|     \\ \\  \\     \\ \\  \\        \\ \\  \\______\\  \\       \\ \\  \\     \\  \\             ");
	sample.push_back(" \\ \\  \\		\\ \\  \\_____\\_\\  \\	 \\ \\   ___   ___\\       \\ \\  \\     \\  \\                         ");
	sample.push_back("  \\ \\  \\		 \\ \\   _______   \\	  \\ \\  \\  \\\\   \\         \\ \\  \\     \\  \\                     ");
	sample.push_back("   \\ \\  \\_________    \\ \\  \\     \\ \\  \\	   \\ \\  \\   \\\\   \\        \\ \\  \\_____\\  \\            ");
	sample.push_back("	\\ \\___________\\    \\ \\__\\     \\ \\__\\	    \\ \\__\\    \\\\ __\\       \\ \\___________\\             ");
	sample.push_back("	 \\|___________|	    \\_|__|     \\_|__|	     \\|__|     \\|__|        \\_|___________|                      ");

	sample.push_back("  ||||||       |       ||||||||  ||||||||");
	sample.push_back(" ||           |||      ||    ||  ||    ||");
	sample.push_back("||           || ||     || ||     ||    ||");
	sample.push_back(" ||         |||||||    ||  ||    ||    ||");
	sample.push_back("  ||||||   ||     ||   ||    ||  ||||||||");

	sample.push_back("||         |||||||||       |       |||||||     ||  ||     ||    ||||||||");
	sample.push_back("||         ||     ||      |||      ||     ||   ||  ||||   ||   ||");
	sample.push_back("||         ||     ||     || ||     ||      ||  ||  || ||  ||  ||");
	sample.push_back("||         ||     ||    |||||||    ||      ||  ||  ||  || ||  ||   |||||");
	sample.push_back("||         ||     ||   ||     ||   ||     ||   ||  ||   ||||   ||     ||");
	sample.push_back("|||||||||  |||||||||  ||       ||  |||||||     ||  ||     ||    ||||||||");

	sample.push_back("||  ||     ||   |||||||  ||||||||  ||||||||  ||    ||    |||||||  ||||||||  ||  ||||||||  ||     ||");
	sample.push_back("||  ||||   ||  ||           ||     ||    ||  ||    ||   ||           ||     ||  ||    ||  ||||   ||");
	sample.push_back("||  || ||  ||    ||         ||     ||||||||  ||    ||  ||            ||     ||  ||    ||  || ||  ||");
	sample.push_back("||  ||  || ||      ||       ||     ||  ||    ||    ||  ||            ||     ||  ||    ||  ||  || ||");
	sample.push_back("||  ||   ||||        ||     ||     ||   ||   ||    ||   ||           ||     ||  ||    ||  ||   ||||");
	sample.push_back("||  ||     ||  |||||||      ||     ||    ||  ||||||||    |||||||     ||     ||  ||||||||  ||     ||");

	sample.push_back("     |       ||||||||    |||||||||  ||     ||  ||||||||||");
	sample.push_back("    |||      ||     ||   ||     ||  ||     ||      ||");
	sample.push_back("   || ||     ||||||||    ||     ||  ||     ||      ||");
	sample.push_back("  |||||||    ||     ||   ||     ||  ||     ||      ||");
	sample.push_back(" ||     ||   ||      ||  ||     ||  ||     ||      ||");
	sample.push_back("||       ||  ||||||||    |||||||||  |||||||||      ||");
}
void chucaro::display_part6(int k)
{
	for (int i = 33; i < sample.size(); i++)
	{
		int key = 33;
		//doi toa do
		_Common::gotoXY(LEFT - 35, TOP + i - key);
		if ((k + i - key) % 16 == 0) k++;
		changecolor((k + i - key) % 16);
		cout << sample[i];
	}
}
void chucaro::display_part5(int k)
{
	for (int i = 27; i < 33; i++)
	{
		int key = 28;
		//doi toa do
		_Common::gotoXY(LEFT - 55, TOP + i - key);
		if ((k + i - key) % 16 == 0) k++;
		changecolor((k + i - key) % 16);
		cout << sample[i];
	}
}
void chucaro::display_part4(int k)
{
	for (int i = 21; i < 27; i++)
	{
		int key = 21;
		_Common::gotoXY(LEFT - 40, TOP + i - key);
		if ((k + i - key) % 16 == 0) k++;
		changecolor((k + i - key) % 16);
		cout << sample[i];
	}
}
void chucaro::display_part3(int k)
{
	for (int i = 16; i < 21; i++)
	{
		int key = 16;
		_Common::gotoXY(LEFT - 60, 1 + i - key);
		if ((k + i - key) % 16 == 0) k++;
		changecolor((k + i - key) % 16);
		cout << sample[i];
	}
}
void chucaro::display_part1(int k)
{
	for (int i = 0; i < 8; i++)
	{
		_Common::gotoXY(LEFT_MENU - 38, TOP_MENU - 15 + i);
		if ((k + i) % 16 == 0) k++;
		changecolor((k + i) % 16);
		cout << sample[i];
	}
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
	Sleep(400);
}
void chucaro::display_part2(int k)
{
	for (int i = 8; i < 16; i++)
	{
		int key = 8;
		_Common::gotoXY(LEFT_MENU - 38, TOP_MENU - 15 + i - key);
		if ((k + i - key) % 16 == 0) k++;
		changecolor((k + i - key) % 16);
		cout << sample[i];
	}
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
	Sleep(400);
}