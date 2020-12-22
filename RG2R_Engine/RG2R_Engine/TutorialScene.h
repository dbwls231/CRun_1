#pragma once
#include "Scene.h"
class TutorialScene :
	public Scene
{
private:
	Object* tutorial;
public:
	TutorialScene();
	~TutorialScene();

	void OnUpdate();
};

