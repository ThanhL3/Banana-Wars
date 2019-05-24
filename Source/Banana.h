#pragma once

#include "Definition.h"

class Banana
{
public:
	Banana(string Type1, uint32_t Power1, uint32_t Count1)
		: Type(Type1), Power(Power1), Count(Count1)
	{}

	~Banana();
	string   returnType();
	uint32_t returnPower();
	uint32_t returnCount();
	void	 setCount(uint32_t count);

private:
	string      Type;
	uint32_t    Power;
	uint32_t	Count;
};

