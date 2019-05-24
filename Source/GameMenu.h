#pragma once

/*
This class handles all of the game state transitions.
*/

#include "Definition.h"
#include "BananaArmy.h"
#include "Conquest.h"

class GameMenu
{
public:
	enum gameState { INTRO, MENU, ARMY, SHOP, CONQUEST, SUMMARY };
	
	GameMenu();

	~GameMenu();

	void showState();

	void setState(std::string state);

	void showIntro();

	void showMenu();

	void showDefault();

	void showShop();

	void showSummary();
private:
	gameState currState;
	BananaArmy *Army;
	Conquest* Quest;
	string input;
};

