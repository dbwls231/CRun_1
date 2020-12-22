#include "stdafx.h"
#include "FifthGScene.h"
#include "SpriteRenderer.h"
#include "Transform.h"

#include "Engine.h"
#include "MainScene.h"
#include "FirstGScene.h"
FifthGScene::FifthGScene(float point):plusPoint(point)
{
	player = new Player(4);

	bg.push_back(new Background("Resources/Image/Background/Circle/gray.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/pink.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/orange.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/blue.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/purple.png"));
	for (auto iter : bg) {
		AttachObject(iter);
		player->AttachChild(iter);
		iter->GetTransform()->SetScale(0, 0);
	}
	bg[0]->GetTransform()->SetScale(4, 4);
	AttachObject(player);

	for (int i = 0; i < 3; i++) {
		floor.push_back(new Object());
		floor[i]->AttachComponent<SpriteRenderer>()
			->SetTexture("Resources/Image/MapObject/floor.png");
		floor[i]->AttachComponent<Transform>()
			->SetPos(-5.21 + i * 10.43, -2);
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
		hps.push_back(new Hp("Resources/Image/UI/Life.png", -0.1f + i * 0.1f, 0.32f));
		AttachObject(hps[i]);
		player->AttachChild(hps[i]);
	}

	left = new UI("Resources/Image/UI/bgChoice/left.png", -4.75, 2.05);
	right = new UI("Resources/Image/UI/bgChoice/right.png", -3.9, 2.05);
	AttachObject(left);
	AttachObject(right);

	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/black_big.png", "Resources/Image/UI/bgChoice/black_small.png"));
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/pink_big.png", "Resources/Image/UI/bgChoice/pink_small.png"));
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/orange_big.png", "Resources/Image/UI/bgChoice/orange_small.png"));
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/blue_big.png", "Resources/Image/UI/bgChoice/blue_small.png"));
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/purple_big.png", "Resources/Image/UI/bgChoice/purple_small.png"));
	for (auto iter : bgUi)
		AttachObject(iter);

	

	
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/lazer_orange.png", 10, 0.223));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/lazer_pink.png", 14, 0.223));
	obstacles.push_back(new Obstacle(4, "Resources/Image/MapObject/Obstacle/Purple/lazer_purple.png", 18, 0.223));
	obstacles.push_back(new Obstacle(3, "Resources/Image/MapObject/Obstacle/Blue/lazer_blue.png", 22, 0.223));
	
	obstacles.push_back(new Obstacle(4, "Resources/Image/MapObject/Obstacle/Purple/lazer_purple.png", 30, 0.223));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/lazer_pink.png", 34, 0.223));
	obstacles.push_back(new Obstacle(3, "Resources/Image/MapObject/Obstacle/Blue/lazer_blue.png", 38, 0.223));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/lazer_orange.png", 42, 0.223));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/lazer_pink.png", 46, 0.223));
	obstacles.push_back(new Obstacle(4, "Resources/Image/MapObject/Obstacle/Purple/lazer_purple.png", 49, 0.223));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/lazer_orange.png", 52, 0.223));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/lazer_orange.png", 55, 0.223));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/lazer_pink.png", 58, 0.223));
	obstacles.push_back(new Obstacle(4, "Resources/Image/MapObject/Obstacle/Purple/lazer_purple.png", 60, 0.223));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/lazer_orange.png", 62, 0.223));

	for (auto iter : obstacles) {
		AttachObject(iter);
	}

	for (auto iter : floors) {
		AttachObject(iter);
		iter->SetTag("Floor");
	}
	pauseBg = CreateObject();
	pauseBg->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/Image/UI/Pause/pauseBg.png")
		->SetZ_index(4);
	pauseBg->AttachComponent<BoxCollider>()->SetAreaAuto();
	pauseBg->AttachComponent<Transform>()
		->SetAnchor(pauseBg->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(0, -10)
		->SetIsRelative(false);

	exit = CreateObject();
	exit->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/Image/UI/Pause/pause-exit.png")
		->SetZ_index(5);
	exit->AttachComponent<BoxCollider>()->SetAreaAuto();
	exit->AttachComponent<Transform>()
		->SetAnchor(exit->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(-2, -10)
		->SetIsRelative(false);
	restart = CreateObject();
	restart->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/Image/UI/Pause/pause-restart.png")
		->SetZ_index(5);
	restart->AttachComponent<BoxCollider>()->SetAreaAuto();
	restart->AttachComponent<Transform>()
		->SetAnchor(exit->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(2, -10)
		->SetIsRelative(false);
	play=CreateObject();
	play->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/Image/UI/Pause/pause-play.png")
		->SetZ_index(5);
	play->AttachComponent<BoxCollider>()->SetAreaAuto();
	play->AttachComponent<Transform>()
		->SetAnchor(exit->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(0, -10)
		->SetIsRelative(false);



}

FifthGScene::~FifthGScene()
{
	delete player;
	delete left;
	delete right;
	delete play;
	delete exit;
	delete restart;
	delete pauseBg;
	for (auto iter : floors)
		delete iter;
	for (auto iter : ceiling)
		delete iter;
	for (auto iter : hps)
		delete iter;
	for (auto iter : floors)
		delete iter;
	for (auto iter : obstacles)
		delete iter;
	for (auto iter : bg)
		delete iter;
	for (auto iter : bgUi)
		delete iter;
}

void FifthGScene::OnUpdate()
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
		for (int i = 0; i < 4; i++) {
			if (i != currentBg && bg[i]->GetTransform()->GetScale().x >= 0.0f) {
				bg[i]->GetTransform()->SetScale(bg[i]->GetTransform()->GetScale() - Vec2F(8, 8) * RG2R_TimeM->GetDeltaTime());

				if (bg[i]->GetTransform()->GetScale().x < 0.0f)
					bg[i]->GetTransform()->SetScale(0, 0);
			}

		}
		if (bg[currentBg]->GetTransform()->GetScale().x < 4)
			bg[currentBg]->GetTransform()->SetScale(bg[currentBg]->GetTransform()->GetScale().x + 8 * RG2R_TimeM->GetDeltaTime(), bg[currentBg]->GetTransform()->GetScale().y + 8 * RG2R_TimeM->GetDeltaTime());

		if (currentPosX > 65) {
			cout << "Clear" << endl;
			RG2R_SceneM->ChangeScene(new EndingScene(100000));
		}
	}

	if (RG2R_InputM->GetKeyState(KeyCode::KEY_ESCAPE) == KeyState::KEYSTATE_ENTER) {
		if (isPlaying) {
			isPlaying = false;
			player->SetIsPlaying(false);
			pauseBg->GetComponent<Transform>()->SetPosY(0);
			exit->GetComponent<Transform>()->SetPosY(0);
			restart->GetComponent<Transform>()->SetPosY(0);
		}
		else {
			isPlaying = true;
			player->SetIsPlaying(true);
			pauseBg->GetComponent<Transform>()->SetPosY(-10);
			exit->GetComponent<Transform>()->SetPosY(-10);
			restart->GetComponent<Transform>()->SetPosY(-10);
		}
	}
	if (!isPlaying) {
		if (RG2R_InputM->GetKeyState(KeyCode::KEY_B) == KeyState::KEYSTATE_ENTER) {
			RG2R_SceneM->ChangeScene(new MainScene());
		}
		else if (RG2R_InputM->GetKeyState(KeyCode::KEY_L) == KeyState::KEYSTATE_ENTER) {
			RG2R_SceneM->ChangeScene(new FirstGScene());
		}
	}
}

void FifthGScene::OnStart()
{
	bgUi[0]->isCurrentBg();
	bgUi[2]->isNotUsed();
	bgUi[1]->isSideBg(1);
	bgUi[3]->isNotUsed();
	bgUi[4]->isSideBg(-1);
}

void FifthGScene::GameOver()
{
	cout << "GameOver" << endl;
	RG2R_SceneM->ChangeScene(new EndingScene((currentPosX + 3) / 4 + plusPoint));
}

void FifthGScene::ChangeHp(int currentHp, int changeHp)
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

void FifthGScene::ChangeBg(int currentBG)
{
	if (currentBG == 0) {
		bgUi[0]->isCurrentBg();
		bgUi[1]->isSideBg(1);
		bgUi[2]->isNotUsed();
		bgUi[3]->isNotUsed();
		bgUi[4]->isSideBg(-1);
	}
	else if (currentBG == 1) {
		bgUi[0]->isSideBg(-1);
		bgUi[1]->isCurrentBg();
		bgUi[2]->isSideBg(1);
		bgUi[3]->isNotUsed();
		bgUi[4]->isNotUsed();
	}
	else if (currentBG == 2) {
		bgUi[0]->isNotUsed();
		bgUi[1]->isSideBg(-1);
		bgUi[2]->isCurrentBg();
		bgUi[3]->isSideBg(1);
		bgUi[4]->isNotUsed();
	}
	else if(currentBG==3) {
		bgUi[0]->isNotUsed();
		bgUi[1]->isNotUsed();
		bgUi[2]->isSideBg(-1);
		bgUi[3]->isCurrentBg();
		bgUi[4]->isSideBg(1);
	}
	else {
		bgUi[0]->isSideBg(1);
		bgUi[1]->isNotUsed();
		bgUi[2]->isNotUsed();
		bgUi[3]->isSideBg(-1);
		bgUi[4]->isCurrentBg();
	}
	currentBg = currentBG;
}
