#pragma once
#include "Scene.h"
#include "GameObject.h"

class GameObject;

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	GameObject* AttachObject(GameObject*);
	Object* AttachObject(Object*);

	/* �����ֱ� */

	virtual void OnStart(){}
	virtual void OnUpdate(){}
	
};

