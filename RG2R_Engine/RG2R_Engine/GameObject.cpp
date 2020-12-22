#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

Transform* GameObject::GetTransform()
{
	return GetComponent<Transform>();
}

GameScene* GameObject::GetScene()
{
	return (GameScene*)Object::GetScene();
}
