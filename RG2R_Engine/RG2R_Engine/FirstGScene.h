#pragma once
#include "Scene.h"

#include "Player.h"
#include "Obstacle.h"
#include "Hp.h"
#include "BgUI.h"
#include "Background.h"


class FirstGScene :
	public Scene
{
private:
	int plusPoint=0;
	int currentObN = 0;
	int objectMgN = 0;
	float currentPosX=-3;
	float checkPosX=0;
	float anim_timeCheck = 0;
	bool isPlaying=true;
	bool isGround=false;
	bool isJump=false;
	bool isSecondJump=false;
	bool isSlide = false;

	
	Player* player;
	Background* blackBg;
	Object* blackBgUi;
	Object* pauseBg;
	Object* play;
	Object* exit;
	Object* restart;

	std::vector<Hp*> hps;
	std::vector<Obstacle*> floors;
	std::vector<Obstacle*> obstacles;
	std::vector<Object*> floor;
	std::vector<Object*> ceiling;


public:
	FirstGScene();
	~FirstGScene();

	void OnUpdate();
	void GameOver();
	void ChangeHp(int,int);
};

