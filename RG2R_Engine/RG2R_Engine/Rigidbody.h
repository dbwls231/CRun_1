#pragma once
#include "Component.h"

#include <map>

class CollisionInfo;

class Rigidbody :
	public Component
{
private:
	Vec2F acceleration = { 0,0 };
	Vec2F velocity = { 0,0 };

	float calculation_speed = 15;

	std::map<Object*, bool> isFirstCollision;
public:
	Rigidbody();
	~Rigidbody();

	void Update();
	void Render();
	void Render(ViewRenderData&);

	std::type_index GetID() { return typeid(Rigidbody); }
	static std::type_index GetFamilyID(void) { return typeid(Rigidbody); }

	Rigidbody* SetForce(Vec2F);
	Rigidbody* SetForce(float, float);
	Rigidbody* AddForce(Vec2F);
	Rigidbody* AddForce(float, float);
	Rigidbody* SetCalculationSpeed(float);

	Vec2F GetForce();
	float GetCalculationSpeed();
};
