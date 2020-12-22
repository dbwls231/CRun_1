#pragma once
#include "GameObject.h"

#include "Rigidbody.h"
#include "BoxCollider.h"
#include <string>

class Obstacle : //�ε����� ������ ���°�
	public GameObject
{
private:
	Rigidbody* rigidbody;
	BoxCollider* boxcollider;
	float x, y;
	std::string texture;
public:
	Obstacle(int, std::string, float, float);
	~Obstacle();

	void OnStart();
	
};

