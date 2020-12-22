#pragma once
#include "Object.h"

#include "GameScene.h"
#include "Transform.h"

class GameScene;

class GameObject :
	public Object
{
public:
	GameObject();
	~GameObject();

	Transform* GetTransform();
	GameScene* GetScene();
};

