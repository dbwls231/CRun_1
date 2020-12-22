#pragma once
#include "GameScene.h"
#include "Background.h"
#include "Engine.h"
#include "Button.h"

class MainScene :
	public GameScene
{
	Background* bg;
	Object* playBtn;
	Object* tutorialBtn;
	Object* exitBtn;
public:
	MainScene();
	~MainScene();
	void OnUpdate();
};
