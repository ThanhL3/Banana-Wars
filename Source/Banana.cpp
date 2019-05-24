#include "Banana.h"


Banana::~Banana()
{

}

string Banana::returnType()
{
	return Type;
}

uint32_t Banana::returnPower()
{
	return Power;
}

uint32_t Banana::returnCount()
{
	return Count;
}

void Banana::setCount(uint32_t count)
{
	Count = count;
}