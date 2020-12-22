#pragma once
#include "GameObject.h"
class BgUI :
	public GameObject
{
	std::string bigBg;
	std::string smallBg;
public:
	BgUI(std::string, std::string);
	~BgUI();

	void OnStart();

	void isCurrentBg();
	void isSideBg(int);
	void isNotUsed();

	void Test();
};

