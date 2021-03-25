#include "win_lose_draw.h"
#include "_Common.h"

win_lose_draw::win_lose_draw()
{ //loser 0
	sample.push_back(Charac(219, 2) + Space(11) + Charac(219, 8) + Space(5) + Charac(219, 8) + Space(5) + Charac(219, 7) + Space(4) + Charac(219, 9));
	sample.push_back(Charac(219, 2) + Space(10) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(11) + Charac(219, 2) + Space(10) + Charac(219, 2) + Space(7) + Charac(219, 2));
	sample.push_back(Charac(219, 2) + Space(10) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(5) + Charac(219, 2) + Space(9) + Charac(219, 2) + Space(10) + Charac(219, 10));
	sample.push_back(Charac(219, 2) + Space(10) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(7) + Charac(219, 2) + Space(7) + Charac(219, 7) + Space(5) + Charac(219, 2) + Space(1) + Charac(219, 2));
	sample.push_back(Charac(219, 2) + Space(10) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(9) + Charac(219, 2) + Space(5) + Charac(219, 2) + Space(10) + Charac(219, 2) + Space(3) + Charac(219, 2));
	sample.push_back(Charac(219, 2) + Space(10) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(11) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(10) + Charac(219, 2) + Space(5) + Charac(219, 2));
	sample.push_back(Charac(219, 9) + Space(4) + Charac(219, 8) + Space(5) + Charac(219, 8) + Space(5) + Charac(219, 7) + Space(4) + Charac(219, 2) + Space(6) + Charac(219, 2));
	//winner 7
	sample.push_back(Charac(219, 2) + Space(9) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(3) + Charac(219, 2) +
		Space(7) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(7) + Charac(219, 2) + Space(4) + Charac(219, 7) +
		Space(3) + Charac(219, 8));
	sample.push_back(Charac(219, 2) + Space(9) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(3) + Charac(219, 4) + Space(5) +
		Charac(219, 2) + Space(3) + Charac(219, 4) + Space(5) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(9) +
		Charac(219, 2) + Space(5) + Charac(219, 2));
	sample.push_back(Charac(219, 2) + Space(4) + Charac(219, 1) + Space(4) + Charac(219, 2) + Space(3) + Charac(219, 2) +
		Space(3) + Charac(219, 2) + Space(1) + Charac(219, 2) + Space(4) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(1) +
		Charac(219, 2) + Space(4) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(9) + Charac(219, 8));
	sample.push_back(Charac(219, 2) + Space(3) + Charac(219, 3) + Space(3) + Charac(219, 2) + Space(3) + Charac(219, 2) +
		Space(3) + Charac(219, 2) + Space(2) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(2) +
		Charac(219, 2) + Space(3) + Charac(219, 2) + Space(3) + Charac(219, 7) + Space(4) + Charac(219, 2) + Space(2) + Charac(219, 2));
	sample.push_back(Charac(219, 2) + Space(3) + Charac(219, 3) + Space(3) + Charac(219, 2) + Space(3) + Charac(219, 2) +
		Space(3) + Charac(219, 2) + Space(4) + Charac(219, 2) + Space(1) + Charac(219, 2) + Space(3) + Charac(219, 2) +
		Space(4) + Charac(219, 2) + Space(1) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(9) + Charac(219, 2) + Space(3) +
		Charac(219, 2));
	sample.push_back(Space(1) + Charac(219, 3) + Space(5) + Charac(219, 3) + Space(4) + Charac(219, 2) +
		Space(3) + Charac(219, 2) + Space(5) + Charac(219, 4) + Space(3) + Charac(219, 2) + Space(5) + Charac(219, 4) +
		Space(3) + Charac(219, 2) + Space(9) + Charac(219, 2) + Space(4) + Charac(219, 2));
	sample.push_back(Space(2) + Charac(219, 9) + Space(5) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(7) + Charac(219, 2) +
		Space(3) + Charac(219, 2) + Space(7) + Charac(219, 2) + Space(4) + Charac(219, 7) +
		Space(3) + Charac(219, 2) + Space(5) + Charac(219, 2));
	//x is 14
	sample.push_back(Space(16) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(21 - 6) + Charac(219, 2) + Space(3) + Charac(219, 7));
	sample.push_back(Space(17) + Charac(219, 2) + Space(4) + Charac(219, 2) + Space(22 - 6) + Charac(219, 2) + Space(2) + Charac(219, 2));
	sample.push_back(Space(18) + Charac(219, 2) + Space(2) + Charac(219, 2) + Space(23 - 6) + Charac(219, 2) + Space(4) + Charac(219, 2));
	sample.push_back(Space(19) + Charac(219, 4) + Space(24 - 6) + Charac(219, 2) + Space(6) + Charac(219, 2));
	sample.push_back(Space(18) + Charac(219, 2) + Space(2) + Charac(219, 2) + Space(23 - 6) + Charac(219, 2) + Space(8) + Charac(219, 2));
	sample.push_back(Space(17) + Charac(219, 2) + Space(4) + Charac(219, 2) + Space(22 - 6) + Charac(219, 2) + Space(9) + Charac(219, 2));
	sample.push_back(Space(16) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(21 - 6) + Charac(219, 2) + Space(3) + Charac(219, 7));
	//o is 21
	sample.push_back(Space(17) + Charac(219, 8) + Space(22 - 6) + Charac(219, 2) + Space(3) + Charac(219, 7));
	sample.push_back(Space(16) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(21 - 6) + Charac(219, 2) + Space(2) + Charac(219, 2));
	sample.push_back(Space(16) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(21 - 6) + Charac(219, 2) + Space(4) + Charac(219, 2));
	sample.push_back(Space(16) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(21 - 6) + Charac(219, 2) + Space(6) + Charac(219, 2));
	sample.push_back(Space(16) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(21 - 6) + Charac(219, 2) + Space(8) + Charac(219, 2));
	sample.push_back(Space(16) + Charac(219, 2) + Space(6) + Charac(219, 2) + Space(21 - 6) + Charac(219, 2) + Space(9) + Charac(219, 2));
	sample.push_back(Space(17) + Charac(219, 8) + Space(22 - 6) + Charac(219, 2) + Space(3) + Charac(219, 7));

	//drawn 28
	sample.push_back(Charac(219, 8) + Space(7) + Charac(219, 8) + Space(10) + Charac(219, 1) + Space(9) + Charac(219, 2) + Space(9) +
		Charac(219, 2) + Space(3) + Charac(219, 2) + Space(7) + Charac(219, 2));
	sample.push_back(Charac(219, 2) + Space(6) + Charac(219, 2) + Space(5) + Charac(219, 2) + Space(5) + Charac(219, 2) + Space(8) +
		Charac(219, 3) + Space(8) + Charac(219, 2) + Space(9) + Charac(219, 2) + Space(3) + Charac(219, 4) + Space(5) + Charac(219, 2));
	sample.push_back(Charac(219, 2) + Space(7) + Charac(219, 2) + Space(4) + Charac(219, 8) + Space(8) + Charac(219, 2) + Space(1) +
		Charac(219, 2) + Space(7) + Charac(219, 2) + Space(4) + Charac(219, 1) + Space(4) + Charac(219, 2) +
		Space(3) + Charac(219, 2) + Space(1) + Charac(219, 2) + Space(4) + Charac(219, 2));
	sample.push_back(Charac(219, 2) + Space(8) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(2) + Charac(219, 2) + Space(9) +
		Charac(219, 7) + Space(6) + Charac(219, 2) + Space(3) + Charac(219, 3) + Space(3) + Charac(219, 2) + Space(3) + Charac(219, 2) +
		Space(2) + Charac(219, 2) + Space(3) + Charac(219, 2));
	sample.push_back(Charac(219, 2) + Space(7) + Charac(219, 2) + Space(4) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(7) +
		Charac(219, 2) + Space(5) + Charac(219, 2) + Space(5) + Charac(219, 2) + Space(3) + Charac(219, 3) + Space(3) + Charac(219, 2) +
		Space(3) + Charac(219, 2) + Space(4) + Charac(219, 2) + Space(1) + Charac(219, 2));
	sample.push_back(Charac(219, 2) + Space(6) + Charac(219, 2) + Space(5) + Charac(219, 2) + Space(4) + Charac(219, 2) + Space(5) +
		Charac(219, 2) + Space(7) + Charac(219, 2) + Space(5) + Charac(219, 3) + Space(5) + Charac(219, 3) + Space(4) + Charac(219, 2) +
		Space(5) + Charac(219, 4));
	sample.push_back(Charac(219, 8) + Space(7) + Charac(219, 2) + Space(5) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(9) +
		Charac(219, 2) + Space(5) + Charac(219, 9) + Space(5) + Charac(219, 2) + Space(7) + Charac(219, 2));
	//game 35
	sample.push_back(Space(10) + Charac(219, 8) + Space(11) + Charac(219, 1) + Space(9) + Charac(219, 2) + Space(8) + Charac(219, 2) +
		Space(4) + Charac(219, 8));
	sample.push_back(Space(8) + Charac(219, 2) + Space(8) + Charac(219, 2) + Space(8) + Charac(219, 3) + Space(8) + Charac(219, 3) +
		Space(6) + Charac(219, 3) + Space(3) + Charac(219, 2));
	sample.push_back(Space(8) + Charac(219, 2) + Space(17) + Charac(219, 2) + Space(1) + Charac(219, 2) + Space(7) + Charac(219, 2) +
		Space(1) + Charac(219, 2) + Space(2) + Charac(219, 2) + Space(1) + Charac(219, 2) + Space(3) + Charac(219, 2));
	sample.push_back(Space(8) + Charac(219, 2) + Space(3) + Charac(219, 7) + Space(6) + Charac(219, 7) + Space(6) + Charac(219, 2) +
		Space(2) + Charac(219, 4) + Space(2) + Charac(219, 2) + Space(3) + Charac(219, 7));
	sample.push_back(Space(8) + Charac(219, 2) + Space(8) + Charac(219, 2) + Space(5) + Charac(219, 2) + Space(5) + Charac(219, 2) +
		Space(5) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(3) + Charac(219, 2) + Space(3) + Charac(219, 2));
	sample.push_back(Space(8) + Charac(219, 2) + Space(8) + Charac(219, 2) + Space(4) + Charac(219, 2) + Space(7) + Charac(219, 2) +
		Space(4) + Charac(219, 2) + Space(8) + Charac(219, 2) + Space(3) + Charac(219, 2));
	sample.push_back(Space(10) + Charac(219, 8) + Space(5) + Charac(219, 2) + Space(9) + Charac(219, 2) + Space(3) + Charac(219, 2) +
		Space(8) + Charac(219, 2) + Space(4) + Charac(219, 8));
}
void win_lose_draw::Display_Loser(int k)
{
	if (k % 16 == 0) k++;
	for (int i = 0; i < 7; i++)
	{
		_Common::gotoXY(45, 12 + i);
		if ((k + i) % 16 == 0) k++;
		changecolor((k + i) % 16);
		cout << sample[i];
	}
}
void win_lose_draw::Display_Winner(int k)
{
	if (k % 16 == 0) k++;
	for (int i = 7; i < 14; i++)
	{
		_Common::gotoXY(40, 5 + i);
		if ((k + i) % 16 == 0) k++;
		changecolor((k + i) % 16);
		cout << sample[i];
	}

}
void win_lose_draw::Display_XIS(int k)
{
	if (k % 16 == 0) k++;
	for (int i = 14; i < 21; i++)
	{
		_Common::gotoXY(40, 3 + i - 14);
		if ((k + i) % 16 == 0) k++;
		changecolor((k + i) % 16);
		cout << sample[i];
	}
}
void win_lose_draw::Display_OIS(int k)
{
	if (k % 16 == 0) k++;
	for (int i = 21; i < 28; i++)
	{
		_Common::gotoXY(40, 3 + i - 21);
		if ((k + i) % 16 == 0) k++;
		changecolor((k + i) % 16);
		cout << sample[i];
	}
}
void win_lose_draw::Display_Drawn(int k)
{
	if (k % 16 == 0) k++;
	for (int i = 28; i < 35; i++)
	{
		_Common::gotoXY(40, 3 + i - 28);
		if ((k + i) % 16 == 0) k++;
		changecolor((k + i) % 16);
		cout << sample[i];
	}

	for (int i = 35; i < sample.size(); i++)
	{
		_Common::gotoXY(40, 12 + i - 35);
		if ((k + i) % 16 == 0) k++;
		changecolor((k + i) % 16);
		cout << sample[i];
	}
}