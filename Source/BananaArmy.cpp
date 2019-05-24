#include "BananaArmy.h"



BananaArmy::BananaArmy()
{
	CivilianBanana = new Banana("Civilian", 3, 4);
	PrivateBanana = new Banana("Private", 5, 2);
	MediocreBanana = new Banana("Mediocre", 8, 0);
	JediBanana = new Banana("Jedi", 15, 0);
	SuperBanana = new Banana("Super", 40, 0);
	Kiwis = 0;
}


BananaArmy::~BananaArmy()
{
	delete CivilianBanana;
	delete PrivateBanana;
	delete MediocreBanana;
	delete JediBanana;
	delete SuperBanana;
}

void BananaArmy::changeArmy(string type)
{
	uint32_t currCount;
	if (type == "Civilian" && Kiwis >= 2)
	{
		currCount = CivilianBanana->returnCount();
		currCount++;
		CivilianBanana->setCount(currCount);
		Kiwis -= 2;
	}
	else if (type == "Private" && Kiwis >= 3)
	{
		currCount = PrivateBanana->returnCount();
		currCount++;
		PrivateBanana->setCount(currCount);
		Kiwis -= 3;
	}
	else if (type == "Mediocre" && Kiwis >= 5)
	{
		currCount = MediocreBanana->returnCount();
		currCount++;
		MediocreBanana->setCount(currCount);
		Kiwis -= 5;
	}
	else if (type == "Jedi" && Kiwis >= 10)
	{
		currCount = JediBanana->returnCount();
		currCount++;
		JediBanana->setCount(currCount);
		Kiwis -= 10;
	}
	else if (type == "Super" && Kiwis >= 30)
	{
		currCount = SuperBanana->returnCount();
		currCount++;
		SuperBanana->setCount(currCount);
		Kiwis -= 30;
	}
}

void BananaArmy::showArmy()
{
	uint32_t civCount = CivilianBanana->returnCount();
	uint32_t privCount = PrivateBanana->returnCount();
	uint32_t medCount = MediocreBanana->returnCount();
	uint32_t jedCount = JediBanana->returnCount();
	uint32_t supCount = SuperBanana->returnCount();

	std::cout << "\n\n\n\n\n\n\n\n\n";

	std::cout << "                                                  YOUR CURRENT BANANAS ARMY      \n\n\n";

	std::cout << "                                                     CIVILIAN BANANA: " << civCount << "              \n\n\n";

	std::cout << "                                                      PRIVATE BANANA: " << privCount << "             \n\n\n";

	std::cout << "	                                             MEDIOCRE BANANA: " << medCount << "            \n\n\n";

	std::cout << "				                         JEDI BANANA: " << jedCount << "            \n\n\n";

	std::cout << "			                                SUPER BANANA: " << supCount << "          \n\n\n";

	std::cout << "PLEASE INPUT THE MODE THAT YOU WANT TO GO TO: ";
}

uint32_t BananaArmy::returnKiwi()
{
	return Kiwis;
}

void BananaArmy::changeKiwi(uint32_t count)
{
	Kiwis += count;
}

uint32_t BananaArmy::returnPower()
{
	uint32_t civCount = CivilianBanana->returnCount();
	uint32_t privCount = PrivateBanana->returnCount();
	uint32_t medCount = MediocreBanana->returnCount();
	uint32_t jedCount = JediBanana->returnCount();
	uint32_t supCount = SuperBanana->returnCount();

	return (civCount * 1) + (privCount * 2) + (medCount * 4) + (jedCount * 8) + (supCount * 200);
}

uint32_t BananaArmy::returnBanana(int index)
{
	uint32_t result;

	switch (index)
	{
	case 1:
		result = CivilianBanana->returnCount();
		break;
	case 2:
		result = PrivateBanana->returnCount();
		break;
	case 3:
		result = MediocreBanana->returnCount();
		break;
	case 4:
		result = JediBanana->returnCount();
		break;
	case 5:
		result = SuperBanana->returnCount();
		break;
	default: result = 0;
	}
	return result;
}