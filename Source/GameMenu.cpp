#include "GameMenu.h"



GameMenu::GameMenu()
{
	currState = INTRO;
	Army = new BananaArmy();
	Quest = new Conquest();
}


GameMenu::~GameMenu()
{
	delete Army;
	delete Quest;
}

void GameMenu::showIntro()
{
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n";

	std::cout << "                                                  WELCOME TO BANANA WARS!      \n\n\n";

	std::cout << "                                                        MAIN MENU              \n\n\n";

	std::cout << "                                                  CURRENT BANANAS ARMY             \n\n\n";

	std::cout << "	                                               BANANA SHOP             \n\n\n";

	std::cout << "	      NOTE: DUE TO BUDGET CUTS AND OTHER TYPICAL EXCUSES, THE GAME ONLY OPERATES USING TERMINAL INPUTS.            \n\n\n                                             WE APOLOGIZE FOR ANY INCONVINIENCE  \n\n\n";

	std::cout << "PLEASE INPUT THE MODE THAT YOU WANT TO GO TO: ";
}
 
void GameMenu::showMenu()
{
	std::cout << "\n\n\n\n\n\n\n\n";

	std::cout << "                                                     MAIN MENU      \n\n\n";

	std::cout << "                                              SHOCKING BANANA CONQUEST              \n\n\n";

	std::cout << "                                               HEROIC BANANA STORIES             \n\n\n";

	std::cout << "	                                         DAILY BANANA DREAMS             \n\n\n";

	std::cout << "	                                       BACK TO STARTING SCREEN              \n\n\n";

	std::cout << "          NOTE: DUE TO BUDGET CUTS AND OTHER TYPICAL EXCUSES, THE GAME ONLY OPERATES USING TERMINAL INPUTS.            \n\n\n                                             WE APOLOGIZE FOR ANY INCONVINIENCE  \n\n\n";

	std::cout << "PLEASE INPUT THE MODE THAT YOU WANT TO GO TO: ";
}

void GameMenu::showDefault()
{
	cout << "\n\n\n\n\n\n\n\n WELL THIS AWKWARD \n\n\n\n THIS SCREEN SHOULD NEVER HAPPEN";
}

void GameMenu::showShop()
{
	std::cout << "\n\n\n\n\n\n\n\n";

	std::cout << "                                               THE ULTRA BODACIOUS BANANAS SHOP 2019      \n\n\n";

	std::cout << "                                                     CIVILIAN BANANA: 2 KIWIS              \n\n\n";

	std::cout << "                                                      PRIVATE BANANA: 3 KIWIS             \n\n\n";

	std::cout << "	                                             MEDIOCRE BANANA: 5 KIWIS            \n\n\n";

	std::cout << "				                         JEDI BANANA: 10 KIWIS           \n\n\n";

	std::cout << "			                                SUPER BANANA: 30 KIWIS         \n\n\n";

	std::cout << "			                                YOUR CURRENT KIWIS: " << Army->returnKiwi() << "\n\n\n";

	std::cout << "WHAT WOULD YOU LIKE TO PURCHASE? ";
}

void GameMenu::showSummary()
{
	cout << "\n\n\n\n\n\n\n\n					     BANANA MISSION SUMMARY \n\n\n ";

	uint32_t randomDifficulty = Quest->returnDifficulty(input);
	uint32_t currentPower = Army->returnPower();
	bool completion = Quest->returnCompletion(input);

	Mission* mission = Quest->returnMission(input);

	uint32_t civCount = Army->returnBanana(1);
	uint32_t privCount = Army->returnBanana(2);
	uint32_t medCount = Army->returnBanana(3);
	uint32_t jedCount = Army->returnBanana(4);
	uint32_t supCount = Army->returnBanana(5);


	

	if (completion == false && (currentPower > randomDifficulty))
	{
		Quest->missionCompleted(input);
		Army->changeKiwi(mission->rewards);
		cout << "		    YOUR ARMY						            ENEMY ARMY\n\n";
		cout << "                Civilian  Banana: " << civCount << "                                                 Evil Oranges    : " << mission->oranges << endl << endl;
		cout << "                Private   Banana: " << privCount << "                                                 Evil Pears      : " << mission->pears << endl << endl;
		cout << "                Mediocre  Banana: " << medCount << "                                                 Evil Cherries   : " << mission->cherries << endl << endl;
		cout << "                Jedi      Banana: " << jedCount << "                                                 Evil Grapes     : " << mission->grapes << endl << endl;
		cout << "                Super     Banana: " << jedCount << "                                                 Evil Apples     : " << mission->apples << endl << endl;
		cout << "\n\n                                              CONGRATULATIONS BANANA LOVER! \n\n                         ";
		cout << "     YOU HAVE SUCCEEDED THE MISSION AND SAVED DOZENS OF BANANAS! \n\n";

	}
	else if (completion == false && (currentPower < randomDifficulty))
	{
		cout << "		    YOUR ARMY						            ENEMY ARMY\n\n";
		cout << "                Civilian  Banana: " << civCount << "                                                 Evil Oranges    : " << mission->oranges << endl << endl;
		cout << "                Private   Banana: " << privCount << "                                                 Evil Pears      : " << mission->pears << endl << endl;
		cout << "                Mediocre  Banana: " << medCount << "                                                 Evil Cherries   : " << mission->cherries << endl << endl;
		cout << "                Jedi      Banana: " << jedCount << "                                                 Evil Grapes     : " << mission->grapes << endl << endl;
		cout << "                Super     Banana: " << jedCount << "                                                 Evil Apples     : " << mission->apples << endl << endl;
		cout << "\n\n                                                    OH NO BANANA LOVER! \n\n                         ";
		cout << "     YOU HAVE FAILED THE MISSION AND fAILED TO SAVE DOZENS OF BANANAS! \n\n";
	}
	else
	{
		cout << "			MISSION ALREADY BEEN COMPLETED, BANANA CITIZENS HAVE BEEN SAVED!			\n\n\n";
	}
	
	cout << "ENTER Y TO RETURN TO CONQUEST: ";
	delete mission;
}

void GameMenu::showState()
{
	switch (currState)
	{
	case INTRO:
		showIntro();
		break;
	case MENU:
		showMenu();
		break;
	case ARMY:
		Army->showArmy();
		break;
	case SHOP:
		showShop();
		break;
	case CONQUEST:
		Quest->showConquest();
		break;
	case SUMMARY:
		showSummary();
		break;
	default: showDefault();
	}
}

void GameMenu::setState(std::string state)
{
	if (state == "Intro") currState = INTRO;
	else if (state == "Menu") currState = MENU;
	else if (state == "Army") currState = ARMY;
	else if (state == "Shop") currState = SHOP;
	else if (state == "Conquest") currState = CONQUEST;
	else if ((currState == SHOP) && (state == "Civilian" || state == "Private" || state == "Mediocre" || state == "Jedi" || state == "Super")) Army->changeArmy(state);
	else if (currState == SUMMARY && (state == "Y")) currState = CONQUEST;
	else if ((currState == CONQUEST) && (state.length() < 3)) currState = SUMMARY;
	input = state;
	std::cout << "\n\n\n";
}

