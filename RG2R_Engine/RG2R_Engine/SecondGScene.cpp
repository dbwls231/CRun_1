#include "stdafx.h"
#include "SecondGScene.h"

#include "SpriteRenderer.h"
#include "Transform.h"

#include "Engine.h"
#include "MainScene.h"
#include "ThirdGScene.h"


SecondGScene::SecondGScene(float plus):plusPoint(plus)
{
	player = new Player(1);

	bg.push_back(new Background("Resources/Image/Background/Circle/gray.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/pink.png"));

	for (auto iter : bg) {
		AttachObject(iter);
		player->AttachChild(iter);
	}
	bg[0]->GetTransform()->SetScale(4, 4);
	bg[1]->GetTransform()->SetScale(0, 0);

	AttachObject(player);


	

	for (int i = 0; i < 3; i++) {
		floor.push_back(new Object());
		floor[i]->AttachComponent<SpriteRenderer>()
			->SetTexture("Resources/Image/MapObject/floor.png");
		floor[i]->AttachComponent<Transform>()
			->SetPos(-5.21 + i * 10.43, -1.8);
		AttachObject(floor[i]);
	}

	for (int i = 0; i < 3; i++) {
		ceiling.push_back(new Object());
		ceiling[i]->AttachComponent<SpriteRenderer>()
			->SetTexture("Resources/Image/MapObject/ceiling.png");
		ceiling[i]->AttachComponent<Transform>()
			->SetPos(-5.21 + i * 10.43, 3);
		AttachObject(ceiling[i]);
	}

	for (int i = 0; i < 3; i++) {
		hpBg.push_back(new Hp("Resources/Image/UI/Life Blank.png", -0.1f + i * 0.1f, 0.32f));
		AttachObject(hpBg[i]);
		player->AttachChild(hpBg[i]);
		hps.push_back(new Hp("Resources/Image/UI/Life.png", -0.1f + i * 0.1f, 0.32f));
		AttachObject(hps[i]);
		player->AttachChild(hps[i]);
	}



	//장애물
	obstacles.push_back(new Obstacle(3, "Resources/Image/MapObject/Obstacle/Blue/Color wall.png", 11.312, - 0.15));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color wall.png", 11.312, - 0.15));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Thorn Up.png", 25.76 ,- 1.64));
	floors.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Floor Magic-Big.png", 26.33, 1.11));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 38.81, - 0.72));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Box.png", 38.81, 1.42));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Double Box1.png", 45.53 ,0.88));
	floors.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Floor Magic.png", 49.61, 2.19));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 50.53, 0.72));
	floors.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Floor Magic.png", 51.47, 2.19));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Double Box2.png", 56.43 ,0.88));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 62.3, - 0.72));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 66.25, - 0.72));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 74.02 ,- 0.72));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block3.png", 77.63, 1.33));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 81, - 0.72));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block2.png", 86.90, 1.33));
	obstacles.push_back(new Obstacle(3, "Resources/Image/MapObject/Obstacle/Blue/Block2.png", 89.26 ,- 0.02));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block1.png", 91.63, 1.33));
	obstacles.push_back(new Obstacle(3, "Resources/Image/MapObject/Obstacle/Blue/Block3.png", 93.79, - 0.02));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block3.png", 96.05, 1.33));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color Wall.png", 103.67, 0.069));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block1.png", 109.37, -1.67));
	obstacles.push_back(new Obstacle(3, "Resources/Image/MapObject/Obstacle/Blue/Box.png", 109.37, -0.47));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Double Box1.png", 109.37, 1.52));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 116.63, 0.72));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Double Box2.png", 122.23, 0.72));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block1.png", 126.71, -1.6));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Double Box1.png", 130, 1.3));
	floors.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Floor Magic.png", 143.36, -0.32));
	floors.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Floor Magic.png", 146.95, -0.32));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Thorn Down.png", 146.95, -1.71));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Thorn Up-big.png", 154.97, 0.65));
	obstacles.push_back(new Obstacle(5, "Resources/Image/MapObject/Obstacle/small/Block3-black_s.png", 159.57, -2.28));
	obstacles.push_back(new Obstacle(5, "Resources/Image/MapObject/Obstacle/small/Block3-black_s.png", 160.48, -2.28));
	obstacles.push_back(new Obstacle(5, "Resources/Image/MapObject/Obstacle/small/Block3-black_s.png", 160.05, -1.33));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 179.52, 0.72));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Box.png", 179.52, -1.6));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 188.30, 0.72));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color Box.png", 188.30, -1.6));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 197.13, 0.72));
	obstacles.push_back(new Obstacle(3, "Resources/Image/MapObject/Obstacle/Blue/Color Box.png", 197.13, -1.6));
	for (auto _floors : floors) {
		AttachObject(_floors);
		(_floors)->SetTag("Floor");
	}

	for (int i = 0; i < 15; i++) {
		AttachObject(obstacles[i]);
	}
	
	left = new UI("Resources/Image/UI/bgChoice/left.png", -4.75, 1.85);

	right = new UI("Resources/Image/UI/bgChoice/right.png", -3.9, 1.85);

	AttachObject(left);
	AttachObject(right);

	blackBgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/black_big.png", "Resources/Image/UI/bgChoice/black_small.png"));
	blackBgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/black_big.png", "Resources/Image/UI/bgChoice/black_small.png"));
	pinkBgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/pink_big.png", "Resources/Image/UI/bgChoice/pink_small.png"));
	pinkBgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/pink_big.png", "Resources/Image/UI/bgChoice/pink_small.png"));

	for (auto iter : blackBgUi)
		AttachObject(iter);
	for (auto iter : pinkBgUi)
		AttachObject(iter);
}

SecondGScene::~SecondGScene()
{
	delete player;
	delete left;
	delete right;
	for (auto iter : floor)
		delete iter;
	for (auto iter : ceiling)
		delete iter;
	for (auto iter : hps)
		delete iter;
	for (auto iter : hpBg)
		delete iter;
	for (auto iter : floors)
		delete iter;
	for (auto iter : obstacles)
		delete iter;
	for (auto iter : bg)
		delete iter;
	for (auto iter : pinkBgUi)
		delete iter;
	for (auto iter : blackBgUi)
		delete iter;
	
}

void SecondGScene::OnUpdate()
{
	if (isPlaying) {
		currentPosX += 4.5 * RG2R_TimeM->GetDeltaTime();
		checkPosX += 4.5 * RG2R_TimeM->GetDeltaTime();
		player->GetTransform()->SetPosX(currentPosX);
		GetMainCamera()->SetPos(currentPosX + 3, 0);
		if (checkPosX > 10.43) {
			floor[currentObN % 3]->GetComponent<Transform>()->Translate(31, 0);
			ceiling[currentObN % 3]->GetComponent<Transform>()->Translate(31, 0);
			currentObN++;
			checkPosX = 0;
		}

		for (int i = 0; i < 2; i++) {
			if (i != currentBg && bg[i]->GetTransform()->GetScale().x >= 0.0f) {
				bg[i]->GetTransform()->SetScale(bg[i]->GetTransform()->GetScale() - Vec2F(8, 8) * RG2R_TimeM->GetDeltaTime());

				if (bg[i]->GetTransform()->GetScale().x < 0.0f)
					bg[i]->GetTransform()->SetScale(0, 0);
			}

		}
		if (bg[currentBg]->GetTransform()->GetScale().x < 4)
			bg[currentBg]->GetTransform()->SetScale(bg[currentBg]->GetTransform()->GetScale().x + 8 * RG2R_TimeM->GetDeltaTime(), bg[currentBg]->GetTransform()->GetScale().y + 8 * RG2R_TimeM->GetDeltaTime());
	}

	if (RG2R_InputM->GetKeyState(KeyCode::KEY_ESCAPE) == KeyState::KEYSTATE_ENTER) {
		if (isPlaying) {
			isPlaying = false;
			player->SetIsPlaying(false);
		}
		else {
			isPlaying = true;
			player->SetIsPlaying(true);
		}
	}

	if (currentPosX > 85 && objectMgN == 0) {
		for (int i = 0; i < 5; i++) {
			obstacles[i]->Destroy();
		}
		for (int i = 15; i < 20; i++) {
			AttachObject(obstacles[i]);
		}
		objectMgN++;
	}
	else if (currentPosX > 95 && objectMgN == 1) {
		for (int i = 5; i < 10; i++) {
			obstacles[i]->Destroy();
		}
		for (int i = 20; i < 25; i++) {
			AttachObject(obstacles[i]);
		}
		objectMgN++;
	}
	else if (currentPosX > 110 && objectMgN == 2) {
		for (int i = 10; i < 15; i++) {
			obstacles[i]->Destroy();
		}
		for (int i = 25; i < 29; i++) {
			AttachObject(obstacles[i]);
		}
		objectMgN++;
	}
	if (currentPosX > 203) {
		cout << "SceneTwoLoad" << endl;
		RG2R_SceneM->ChangeScene(new ThirdGScene(plusPoint));
	}
}

void SecondGScene::OnStart()
{
	blackBgUi[0]->isCurrentBg();
	pinkBgUi[0]->isSideBg(-1);
	pinkBgUi[1]->isSideBg(1);
	blackBgUi[1]->isNotUsed();
}


void SecondGScene::GameOver()
{
	cout << "GameOver" << endl;
	RG2R_SceneM->ChangeScene(new EndingScene((currentPosX + 3) / 4 + plusPoint+50));
}

void SecondGScene::ChangeHp(int currentHp, int changeHp)
{
	if (changeHp == -1) {
		if (currentHp == 1)
			GameOver();
		else
			hps[currentHp - 1]->MinusHp();
	}
	if (changeHp == 1) {
		if (currentHp == 3) //만약에 이미 hp가 3이면 점수에 +
			plusPoint += 10; //나중에 수정 
		else
			hps[currentHp - 1]->PlusHp();
	}
}

void SecondGScene::ChangeBg(int currentBG)
{
	if (currentBG == 0) {
		pinkBgUi[0]->isSideBg(-1);
		pinkBgUi[1]->isSideBg(1);
		blackBgUi[0]->isCurrentBg();
		blackBgUi[1]->isNotUsed();
	}
	else {
		blackBgUi[0]->isSideBg(-1);
		blackBgUi[1]->isSideBg(1);
		pinkBgUi[0]->isCurrentBg();
		pinkBgUi[1]->isNotUsed();
	}
	currentBg = currentBG;
}
