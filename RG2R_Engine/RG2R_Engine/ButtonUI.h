#pragma once
#include "Button.h"
#include "GameObject.h"
#include "Rigidbody.h"
#include "BoxCollider.h"
class ButtonUI :
	public GameObject,public Button
{
	float x, y;
	std::string texture;
	Rigidbody* rigidbody;
	BoxCollider* boxcollider;
public:
	ButtonUI(std::string,float,float);
	~ButtonUI();

	void OnStart();
};

