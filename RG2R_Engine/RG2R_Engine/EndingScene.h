#pragma once
#include "Scene.h"
#include "Object.h"
#include "MainScene.h"
#include "Background.h"
#include "Engine.h"
#include "TextRenderer.h"
#include "Transform.h"
#include "Button.h"
class EndingScene :
	public Scene
{
	Background* bg;
	Object* replayBtn;
	Object* mainBtn;
	float text_posX;
public:
	EndingScene(float);
	~EndingScene();
};

