#include "Conquest.h"



Conquest::Conquest()
{
	M1 = new Mission();
	M2 = new Mission();
	M3 = new Mission();
	M4 = new Mission();
	M5 = new Mission();
	M6 = new Mission();
	M7 = new Mission();
	M8 = new Mission();
	M9 = new Mission();
	M10 = new Mission();

	M1->oranges = 1;
	M1->pears = 1;
	M1->cherries = 0;
	M1->grapes = 0;
	M1->apples = 0;
	M1->missionName = "SAVE BANANA CITY          ";
	M1->rewards = 5;
	M1->completion = "INCOMPLETE";

	M2->oranges = 2;
	M2->pears = 2;
	M2->cherries = 0;
	M2->grapes = 0;
	M2->apples = 0;
	M2->missionName = "SAVE ANOTHER BANANA CITY  ";
	M2->rewards = 15;
	M2->completion = "INCOMPLETE";

	M3->oranges = 3;
	M3->pears = 3;
	M3->cherries = 1;
	M3->grapes = 0;
	M3->apples = 0;
	M3->missionName = "SAVE BANANA COUNTRY       ";
	M3->rewards = 25;
	M3->completion = "INCOMPLETE";

	M4->oranges = 3;
	M4->pears = 3;
	M4->cherries = 2;
	M4->grapes = 0;
	M4->apples = 0;
	M4->missionName = "SAVE BANANA COUNTRY 2     ";
	M4->rewards = 35;
	M4->completion = "INCOMPLETE";

	M5->oranges = 5;
	M5->pears = 5;
	M5->cherries = 2;
	M5->grapes = 0;
	M5->apples = 0;
	M5->missionName = "SAVE BANANA COUNTRY FINALE";
	M5->rewards = 45;
	M5->completion = "INCOMPLETE";

	M6->oranges = 6;
	M6->pears = 6;
	M6->cherries = 3;
	M6->grapes = 1;
	M6->apples = 0;
	M6->missionName = "COME BACK TIME            ";
	M6->rewards = 85;
	M6->completion = "INCOMPLETE";

	M7->oranges = 7;
	M7->pears = 7;
	M7->cherries = 4;
	M7->grapes = 2;
	M7->apples = 0;
	M7->missionName = "INVADE FRUIT LAND         ";
	M7->rewards = 125;
	M7->completion = "INCOMPLETE";

	M8->oranges = 8;
	M8->pears = 8;
	M8->cherries = 5;
	M8->grapes = 3;
	M8->apples = 0;
	M8->missionName = "INVADE FRUIT LAND 2       ";
	M8->rewards = 155;
	M8->completion = "INCOMPLETE";

	M9->oranges = 9;
	M9->pears = 9;
	M9->cherries = 6;
	M9->grapes = 4;
	M9->apples = 1;
	M9->missionName = "CONQUER FRUIT LAND        ";
	M9->rewards = 195;
	M9->completion = "INCOMPLETE";

	M10->oranges = 3;
	M10->pears = 3;
	M10->cherries = 3;
	M10->grapes = 3;
	M10->apples = 3;
	M10->missionName = "THE FINAL SHOWDOWN       ";
	M10->rewards = 305;
	M10->completion = "INCOMPLETE";

	questLine.push_back(*M1);
	questLine.push_back(*M2);
	questLine.push_back(*M3);
	questLine.push_back(*M4);
	questLine.push_back(*M5);
	questLine.push_back(*M6);
	questLine.push_back(*M7);
	questLine.push_back(*M8);
	questLine.push_back(*M9);
	questLine.push_back(*M10);
}


Conquest::~Conquest()
{
	delete M1;
	delete M2;
	delete M3;
	delete M4;
	delete M5;
	delete M6;
	delete M7;
	delete M8;
	delete M9;
	delete M10;
}

void Conquest::showConquest()
{
	vector<Mission>::iterator it;
	int count = 1;
	cout << "\n\n\n					        BANANA CONQUEST MISSIONS			\n\n\n";
	for (it = questLine.begin(); it != questLine.end(); ++it){
		cout << "Mission " << count << " : " << it->missionName << " | " << it->completion << " |" << "\n\n";
		count++;
	}
	cout << "PLEASE CHOOSE A MISSION OR GO TO DIFFERENT MODE: ";
	
}

void Conquest::missionCompleted(string index)
{
	int INDEX = stoi(index);
	questLine[INDEX - 1].completion = "COMPLETED";
}

bool Conquest::returnCompletion(string index)
{
	int INDEX = stoi(index);
	bool result = false;

	if (questLine[INDEX - 1].completion == "COMPLETED") result = true;

	return result;
}

uint32_t Conquest::returnDifficulty(string index)
{
	int INDEX = stoi(index) - 1;
	uint32_t random;
	uint32_t result = 0;

	uint32_t orange = questLine[INDEX].oranges;
	uint32_t pear = questLine[INDEX].pears;
	uint32_t cherry = questLine[INDEX].cherries;
	uint32_t grape = questLine[INDEX].grapes;
	uint32_t apple = questLine[INDEX].apples;
	
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1, 24);
	random = uint32_t(dist(mt));

	if (INDEX < 6) result = (orange * 2) + (pear * 3) + (cherry * 5);
	else result = (orange * 2) + (pear * 3) + (cherry * 5) + (grape * 10) + (apple * 50 * (random / 2));
	
	return result;
}

Mission* Conquest::returnMission(string index)
{
	Mission* m_ptr = new Mission();
	m_ptr = M4;
	int INDEX = stoi(index);

	switch (INDEX)
	{
	case 1:
		m_ptr = M1;
		break;
	case 2:
		m_ptr = M2;
		break;
	case 3:
		m_ptr = M3;
		break;
	case 4:
		m_ptr = M4;
		break;
	case 5:
		m_ptr = M5;
		break;
	case 6:
		m_ptr = M6;
		break;
	case 7:
		m_ptr = M7;
		break;
	case 8:
		m_ptr = M8;
		break;
	case 9:
		m_ptr = M9;
		break;
	case 10:
		m_ptr = M10;
		break;
	default:
		m_ptr->apples = 0;
		m_ptr->pears = 0;
		m_ptr->grapes = 0;
		m_ptr->cherries = 0;
		m_ptr->oranges = 0;
	}

	return m_ptr;
}