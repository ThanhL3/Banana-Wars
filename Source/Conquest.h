#pragma once
#include "Definition.h"

struct Mission
{
	uint32_t oranges = 0;
	uint32_t pears = 0;
	uint32_t cherries = 0;
	uint32_t grapes = 0;
	uint32_t apples = 0;
	uint32_t power = 0;
	uint32_t rewards = 0;
	string completion = "";
	string missionName = "";
};

class Conquest
{
public:
	Conquest();
	
	~Conquest();

	void showConquest();

	void missionCompleted(string index);

	bool returnCompletion(string index);

	uint32_t returnDifficulty(string index);

	Mission* returnMission(string index);

private:
	vector<Mission> questLine;
	Mission* M1;
	Mission* M2;
	Mission* M3;
	Mission* M4;
	Mission* M5;
	Mission* M6;
	Mission* M7;
	Mission* M8;
	Mission* M9;
	Mission* M10;
};

