#pragma once
#include "GameScene.h"

#include "Player.h"
#include "Background.h"
#include "Obstacle.h"
#include "Effect.h"
#include "Hp.h"
#include "BgUI.h"
#include "UI.h"
#include "TextRenderer.h"
#include "Object.h"
#include "EndingScene.h"
#include "MainScene.h"


class PlayScene :
	public GameScene
{
private:
	int currentStage; // 현재 색 몇개까지 나왔는지 0~4
	int currentBG;
	float currentPoint;
	Player* player;
	BgUI* pinkBg;
	BgUI* blackBg;
	UI* left;
	UI* right;


	std::vector<Hp*> hps;
	std::vector<Hp*> hpBg;
	std::vector<Obstacle*> floors;
	std::vector<Obstacle*> obstacles;
	std::vector<Background*> bg;
	std::vector<BgUI*> bgUi;
	
	float startTime;

public:
	PlayScene();
	~PlayScene();

	void OnUpdate();
	void OnStart();

	
	void PlusBG(int);
	void ChangeBG();
	void GameOver();
	void ChangeHp(int,int);
	int GetCurrentBG();
};

