// BananaWar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameMenu.h"

int main()
{
	GameMenu menu = GameMenu();
	string input;

	while (1)
	{
		menu.showState();
		cin >> input;
		menu.setState(input);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

