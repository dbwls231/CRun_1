#pragma once
#include "Scene.h"
#include "Player.h"
#include "Obstacle.h"
#include "Hp.h"
#include "BgUI.h"
#include "Background.h"
#include "Object.h"
#include "UI.h"
#include "EndingScene.h"
class FourthGScene :
	public Scene
{
private:
	float plusPoint = 0;
	int currentObN = 0;
	int currentBg = 0;
	int objectMgN = 0;
	float currentPosX = -3;
	float checkPosX = 0;
	bool isPlaying = true;
	bool isGround = false;
	bool isJump = false;
	bool isSecondJump = false;
	bool isSlide = false;

	Player* player;
	UI* left;
	UI* right;

	std::vector<Hp*> hps;
	std::vector<Hp*> hpBg;
	std::vector<Obstacle*> floors;
	std::vector<Obstacle*> obstacles;
	std::vector<Object*> floor;
	std::vector<Object*> ceiling;
	std::vector<Background*> bg;
	std::vector<BgUI*> bgUi;

public:
	FourthGScene(float);
	~FourthGScene();

	void OnUpdate();
	void OnStart();

	void GameOver();
	void ChangeHp(int, int);
	void ChangeBg(int);
};

