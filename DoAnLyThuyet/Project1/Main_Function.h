#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#pragma warning(disable:4996)
#pragma warning(disable:4018)
#pragma comment( lib, "Winmm.lib" )
#define BOARD_SIZE 15
#define LEFT 80
#define TOP 3
#define LEFT_MENU 66
#define TOP_MENU 22
#define LEFT_LOADING 30
#define TOP_LOADING 18
using namespace std;

string Space(int x);
string Charac(int x, int times);
void changecolor(int n);

void Display_ForDraw();
void Display_ForLoser(bool flag);
void Display_ForWinner(bool flag);


void Display_();
void Display_WithBoard(int k);
void Display_Loading(int k);

void Display_Menu();
void Display_WithInstruction();
void Display_WithAbout();
string Display_Menu_Loading();