#pragma once
#include "GameObject.h"
#include <string>

class Background :
	public GameObject
{
public:
	Background(std::string texture);
	~Background();

};

