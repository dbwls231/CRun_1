#pragma once
#include "Object.h"
class Text :
	public Object
{
	std::string text;
public:
	Text(std::string);
	~Text();
	void OnStart();
};

