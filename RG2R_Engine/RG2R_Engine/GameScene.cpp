#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

GameObject* GameScene::AttachObject(GameObject* object)
{
	Scene::AttachObject(object);
	return object;
}

Object* GameScene::AttachObject(Object* o)
{
	Scene::AttachObject(o);
	return o;
}
