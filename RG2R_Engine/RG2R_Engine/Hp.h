#pragma once
#include "GameObject.h"

class Hp :
	public GameObject
{
	std::string texture;
	float x, y;
public:
	Hp(std::string, float, float);
	~Hp();

	void OnStart();
	void MinusHp();
	void PlusHp();
};

