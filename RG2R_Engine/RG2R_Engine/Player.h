#pragma once
#include "GameObject.h"
#include "Rigidbody.h"
#include "BoxCollider.h"
#include "CollisionInfo.h"
#include "Obstacle.h"
#include "AnimationRenderer.h"

class Player :
	public GameObject
{
private:

	

	int hp;
	int currentFrame = 0;
	int currentBg = 0;
	int currentScene;
	float anim_timeCheck = 0;
	float currentYpower;
	float currentPosX;
	float shieldTime;
	
	bool isShieldOn;
	bool isPlaying;
\
	void PlayerShield();
	void ShieldMg();
	void ChangeBg();
	std::vector<std::string> anim_run;
public:
	Player(int);
	~Player();

	bool isJump;
	bool isSecondJump;
	bool isSlide;
	bool isGround;

	Rigidbody* rigidbody;
	BoxCollider* boxcollider;

	void OnUpdate();
	void OnStart();
	void CheckGround();
	void Movement();
	void AnimationMg();
	void SetIsPlaying(bool);
	void OnCollisionEnter(CollisionInfo*);
	void OnCollisionStay(CollisionInfo*);
	void OnCollisionExit(CollisionInfo*);


};

