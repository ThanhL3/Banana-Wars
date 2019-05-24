#pragma once
#include "Definition.h"
#include "Banana.h"

class BananaArmy
{
public:
	BananaArmy();

	~BananaArmy();

	void changeArmy(string type);

	void showArmy();

	uint32_t returnKiwi();

	void changeKiwi(uint32_t count);

	uint32_t returnPower();

	uint32_t returnBanana(int index);

private:
	Banana *CivilianBanana;
	Banana *PrivateBanana;
	Banana *MediocreBanana;
	Banana *JediBanana;
	Banana *SuperBanana;
	uint32_t Kiwis;
};

