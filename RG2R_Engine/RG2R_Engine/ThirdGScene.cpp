#include "stdafx.h"
#include "ThirdGScene.h"
#include "SpriteRenderer.h"
#include "Transform.h"

#include "Engine.h"
#include "MainScene.h"
#include "FifthGScene.h"
#include "FirstGScene.h"

ThirdGScene::ThirdGScene(float point):plusPoint(point)
{
	player = new Player(2);

	bg.push_back(new Background("Resources/Image/Background/Circle/gray.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/pink.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/orange.png"));
	for (auto iter : bg) {
		AttachObject(iter);
		player->AttachChild(iter);
		iter->GetTransform()->SetScale(0,0);
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
	for (auto iter : bgUi)
		AttachObject(iter);
	  



	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Block2.png", 4.375, -1.6));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Box.png", 12.73, -1.67));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Box.png", 12.73, -0.47));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Box.png", 12.73, 0.73));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color Wall.png", 17.73,0.069));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Wall.png", 22.413, 0.069));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Thorn Down.png", 30.73, -1.94));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 38.73, 0.716));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color Wall.png", 43.73, 0.069));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 48.73, 0.716));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Block1.png", 53.47, -1.6));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Wall.png", 58.17, 0.069));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 69.47, 0.716));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color Wall.png", 76.07, 0.269));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Wall.png", 82.92, 0.269));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color Wall.png", 89.86, 0.269));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Wall.png", 96.49, 0.269));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Block1.png", 101.96, -1.6));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Block2.png", 108.24, -1.6));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Box.png", 115.56, -1.67));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Box.png", 115.56, -0.47));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Box.png", 115.56, 0.73));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color Wall.png", 123.42, 0.27));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Wall.png", 131.42, 0.27));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Thorn Down.png", 141.93, -1.94));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Double Box2.png", 149.93, -1.45));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color Wall.png", 153.42, 0.27));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Box.png", 159.42, -1.6));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color Box.png", 165.42, -1.6));
	obstacles.push_back(new Obstacle(-1, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 173.82, 0.72));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Wall.png", 180.385, 0.27));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color Wall.png", 191.17, 0.27));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Wall.png", 200.82, 0.27));
	
	for (int i = 0; i < 10; i++) {
		AttachObject(obstacles[i]);
	}

	/*for (auto iter : obstacles) {
		AttachObject(iter);
	}*/
	floors.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Floor Magic.png", 30.7, -0.9));
	floors.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Floor Magic.png", 141.62, -0.89));

	
	
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

	bkEffect = CreateObject(); 
	bkEffect->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/Image/Particle.png")
		->SetZ_index(1);
	bkEffect->AttachComponent<Transform>()
		->SetAnchor(bkEffect->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(0, 0);
	bkEffect->AttachComponent<BoxCollider>()->SetAreaAuto();
	bkEffect->GetComponent<Transform>()
		->SetScale(0,0);
	
	//->SetIsRelative(false);
}

ThirdGScene::~ThirdGScene()
{
	delete player;
	delete left;
	delete right;
	delete play;
	delete exit;
	delete restart;
	delete pauseBg;
	delete bkEffect;
	for (auto iter : floors)
		delete iter;
	for (auto iter : ceiling)
		delete iter;
	for (auto iter : hps)
		delete iter;
	for (auto iter : obstacles)
		delete iter;
	for (auto iter : bg)
		delete iter;
	for (auto iter : bgUi)
		delete iter;
}

void ThirdGScene::OnUpdate()
{
	if (isPlaying) {
		currentPosX += 4.5 * RG2R_TimeM->GetDeltaTime();
		checkPosX += 4.5 * RG2R_TimeM->GetDeltaTime();
		Quclzls += RG2R_TimeM->GetDeltaTime();
		bkEffect->AttachComponent<Transform>()->SetPos(currentPosX - 2 + std::cos(Quclzls) * 0.5, (std::sin(Quclzls) + 3) * 0.5 + 1.8);
		player->GetTransform()->SetPosX(currentPosX);
		GetMainCamera()->SetPos(currentPosX + 3, 0);
		if (checkPosX > 10.43) {
			floor[currentObN % 3]->GetComponent<Transform>()->Translate(31, 0);
			ceiling[currentObN % 3]->GetComponent<Transform>()->Translate(31, 0);
			currentObN++;
			checkPosX = 0;
		}
		for (int i = 0; i < 3; i++) {
			if (i != currentBg && bg[i]->GetTransform()->GetScale().x >= 0.0f) {
				bg[i]->GetTransform()->SetScale(bg[i]->GetTransform()->GetScale() - Vec2F(8, 8) * RG2R_TimeM->GetDeltaTime());

				if (bg[i]->GetTransform()->GetScale().x < 0.0f)
					bg[i]->GetTransform()->SetScale(0, 0);
			}

		}
		if (bg[currentBg]->GetTransform()->GetScale().x < 4)
			bg[currentBg]->GetTransform()->SetScale(bg[currentBg]->GetTransform()->GetScale().x + 8 * RG2R_TimeM->GetDeltaTime(), bg[currentBg]->GetTransform()->GetScale().y + 8 * RG2R_TimeM->GetDeltaTime());
		
		if (currentPosX > 205) {
			cout << "fourthSceneLoad" << endl;
			RG2R_SceneM->ChangeScene(new FifthGScene(200));
		}
	}

	if (RG2R_InputM->GetKeyState(KeyCode::KEY_ESCAPE) == KeyState::KEYSTATE_ENTER) {
		if (isPlaying) {
			isPlaying = false;
			player->SetIsPlaying(false);
			pauseBg->GetComponent<Transform>()->SetPosY(0);
			exit->GetComponent<Transform>()->SetPosY(0);
			restart->GetComponent<Transform>()->SetPosY(0);
			play->GetComponent<Transform>()->SetPosY(0);
		}
		else {
			isPlaying = true;
			player->SetIsPlaying(true);
			pauseBg->GetComponent<Transform>()->SetPosY(-10);
			exit->GetComponent<Transform>()->SetPosY(-10);
			restart->GetComponent<Transform>()->SetPosY(-10);
			play->GetComponent<Transform>()->SetPosY(-10);
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

	if (currentPosX > 40 && objectMgN == 0) {
		for (int i = 0; i < 5; i++) {
			obstacles[i]->Destroy();
		}
		for (int i = 10; i < 15; i++) {
			AttachObject(obstacles[i]);
		}
		objectMgN++;
	}
	else if (currentPosX > 75 && objectMgN == 1) {
		
		for (int i = 5; i < 10; i++) {
			obstacles[i]->Destroy();
		}
		for (int i = 15; i < 20; i++) {
			AttachObject(obstacles[i]);
		}
		objectMgN++;
	}
	else if (currentPosX > 100 && objectMgN == 2) {
		for (int i = 10; i < 15; i++) {
			obstacles[i]->Destroy();
		}
		for (int i = 20; i < 25; i++) {
			AttachObject(obstacles[i]);
		}
		objectMgN++;
	}
	else if (currentPosX > 140 && objectMgN == 3) {
		for (int i = 15; i < 20; i++) {
			obstacles[i]->Destroy();
		}
		for (int i = 25; i < 33; i++) {
			AttachObject(obstacles[i]);
		}
		objectMgN++;
	}
	
}

void ThirdGScene::OnStart()
{
	bgUi[0]->isCurrentBg();
	bgUi[2]->isSideBg(-1);
	bgUi[1]->isSideBg(1);
}

void ThirdGScene::GameOver()
{
	cout << "GameOver" << endl;
	RG2R_SceneM->ChangeScene(new EndingScene((currentPosX + 3) / 4 + plusPoint));
}

void ThirdGScene::ChangeHp(int currentHp, int changeHp)
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

void ThirdGScene::ChangeBg(int currentBG)
{
	if (currentBG == 0) {
		bgUi[0]->isCurrentBg();
		bgUi[1]->isSideBg(1);
		bgUi[2]->isSideBg(-1);
	}
	else if (currentBG == 1) {
		bgUi[0]->isSideBg(-1);
		bgUi[1]->isCurrentBg();
		bgUi[2]->isSideBg(1);
	}
	else {
		bgUi[0]->isSideBg(1);
		bgUi[1]->isSideBg(-1);
		bgUi[2]->isCurrentBg();
	}
	currentBg = currentBG;
}
