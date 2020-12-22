#include "stdafx.h"
#include "FirstGScene.h"

#include "SpriteRenderer.h"
#include "Transform.h"
#include "ThirdGScene.h"
#include "MainScene.h"
#include "EndingScene.h"
#include "Engine.h"

FirstGScene::FirstGScene():isPlaying(true)
{
	player = new Player(0);

	blackBg = new Background("Resources/Image/Background/Circle/gray.png");
	blackBg->GetTransform()->SetScale(4, 4);
	player->AttachChild(blackBg);

	AttachObject(player);

	

	for (int i = 0; i <3; i++) {
		floor.push_back(new Object());
		floor[i]->AttachComponent<SpriteRenderer>()
			->SetTexture("Resources/Image/MapObject/floor.png");
		floor[i]->AttachComponent<Transform>()
			->SetPos(-5.21+i*10.43, -2);
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
	

	
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Small/Block3-black_s.png", 14.17, -1.6));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 23.3, 0.71));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Block5.png", 28.8, -1.398));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Block4.png", 32.72, -1.398));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Block2.png", 36.5, -1.4));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Small/Block3-black_s.png", 42, -1.6));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Double Box1.png", 39, 1.3));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 46.9, 0.716));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Block4.png", 54.03, -1.398));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Block5.png", 55.16, -1.4));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 60, 0.71));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Block4.png", 64, -1.398));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 68, 0.71));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Small/Block3-black_s.png", 75, -1.6));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Small/Block3-black_s.png", 80, -1.6));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 84.44, 0.71));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 87.47, 0.71));

	for (int i = 0; i < 10; i++) {
		AttachObject(obstacles[i]);
	}

	blackBgUi = new Object;
	blackBgUi->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/Image/UI/bgChoice/black_big.png");
	blackBgUi->AttachComponent<Transform>()
		->SetPos(-5, 2.2)
		->SetIsRelative(false);
	AttachObject(blackBgUi);

	for (int i = 0; i < 3; i++) {
		hps.push_back(new Hp("Resources/Image/UI/Life.png", -0.1f + i * 0.1f, 0.32f));
		AttachObject(hps[i]);
		player->AttachChild(hps[i]);
	}
	pauseBg = CreateObject();
	pauseBg->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/Image/UI/Pause/pauseBg.png")
		->SetZ_index(4);
	pauseBg->AttachComponent<BoxCollider>()->SetAreaAuto();
	pauseBg->AttachComponent<Transform>()
		->SetAnchor(pauseBg->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(0,-10)
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
	play = CreateObject();
	play->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/Image/UI/Pause/pause-play.png")
		->SetZ_index(5);
	play->AttachComponent<BoxCollider>()->SetAreaAuto();
	play->AttachComponent<Transform>()
		->SetAnchor(exit->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(0, -10)
		->SetIsRelative(false);


	
}

FirstGScene::~FirstGScene()
{
	delete player;
	delete blackBg;
	delete blackBgUi;
	delete play;
	delete exit;
	delete restart;
	delete pauseBg;
	for (auto iter : floor)
		delete iter;
	for (auto iter : ceiling)
		delete iter;
	for (auto iter : hps)
		delete iter;
	for (auto iter : floors)
		delete iter;
	for (auto iter : obstacles)
		delete iter;
}

void FirstGScene::OnUpdate()
{
	if (isPlaying) {
		currentPosX += 4.5 * RG2R_TimeM->GetDeltaTime();
		checkPosX += 4.5 * RG2R_TimeM->GetDeltaTime();
		player->GetTransform()->SetPosX(currentPosX);
		GetMainCamera()->SetPos(currentPosX + 3, 0);
		if (checkPosX > 10.43) {
			floor[currentObN%3]->GetComponent<Transform>()->Translate(31, 0);
			ceiling[currentObN % 3]->GetComponent<Transform>()->Translate(31, 0);
			currentObN++;
			checkPosX = 0;
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

	if (currentPosX > 50 && objectMgN == 0) {
		for (int i = 0; i < 5; i++) {
			obstacles[i]->Destroy();
		}
		for (int i = 10; i < 16; i++) {
			AttachObject(obstacles[i]);
		}
		objectMgN++;
	}
	if (currentPosX > 95) {
		cout << "SceneTwoLoad" << endl;
		RG2R_SceneM->ChangeScene(new ThirdGScene((currentPosX + 3) / 4 + plusPoint));
	}
}



void FirstGScene::GameOver()
{
	cout << "GameOver" << endl;
	RG2R_SceneM->ChangeScene(new EndingScene((currentPosX+3)/4+plusPoint));
}

void FirstGScene::ChangeHp(int currentHp, int changeHp)
{
	if (changeHp == -1) {
		if (currentHp == 1)
			GameOver();
		else
			hps[currentHp-1]->MinusHp();
	}
	if (changeHp == 1) {
		if (currentHp == 3) //만약에 이미 hp가 3이면 점수에 +
			plusPoint += 10; //나중에 수정 
		else 
			hps[currentHp-1]->PlusHp();
	}
}



