#pragma once
#include "GameObject.h"



class UI :
	public GameObject
{
	std::string texture;
	float x, y;
public:
	UI(std::string, float, float);
	~UI();

	void OnStart();
};

