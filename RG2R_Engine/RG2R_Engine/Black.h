#pragma once
#include "GameObject.h"
#include "Rigidbody.h"
#include "BoxCollider.h"

class Black :
	public GameObject
{
private:
	Rigidbody* rigidbody;
	BoxCollider* boxcollider;
public:
	Black();
	~Black();

};

