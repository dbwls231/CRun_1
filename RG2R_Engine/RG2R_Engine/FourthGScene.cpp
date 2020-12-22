#include "stdafx.h"
#include "FourthGScene.h"
#include "SpriteRenderer.h"
#include "Transform.h"

#include "Engine.h"
#include "MainScene.h"

FourthGScene::FourthGScene(float plus):plusPoint(plus)
{

	player = new Player(3);

	//배경
	bg.push_back(new Background("Resources/Image/Background/Circle/gray.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/pink.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/orange.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/blue.png"));

	for (auto iter : bg) {
		AttachObject(iter);
		player->AttachChild(iter);
		iter->GetTransform()->SetScale(0, 0);
	}
	bg[0]->GetTransform()->SetScale(4, 4);
	AttachObject(player);

	//바닥
	for (int i = 0; i < 3; i++) {
		floor.push_back(new Object());
		floor[i]->AttachComponent<SpriteRenderer>()
			->SetTexture("Resources/Image/MapObject/floor.png");
		floor[i]->AttachComponent<Transform>()
			->SetPos(-5.21 + i * 10.43, -2);
		AttachObject(floor[i]);
	}
	//배경
	for (int i = 0; i < 3; i++) {
		ceiling.push_back(new Object());
		ceiling[i]->AttachComponent<SpriteRenderer>()
			->SetTexture("Resources/Image/MapObject/ceiling.png");
		ceiling[i]->AttachComponent<Transform>()
			->SetPos(-5.21 + i * 10.43, 3);
		AttachObject(ceiling[i]);
	}
	//Hp
	for (int i = 0; i < 3; i++) {
		hpBg.push_back(new Hp("Resources/Image/UI/Life Blank.png", -0.1f + i * 0.1f, 0.32f));
		AttachObject(hpBg[i]);
		player->AttachChild(hpBg[i]);
		hps.push_back(new Hp("Resources/Image/UI/Life.png", -0.1f + i * 0.1f, 0.32f));
		AttachObject(hps[i]);
		player->AttachChild(hps[i]);
	}
	for (int i = 0; i < 3; i++) {
		/*hpBg.push_back(new Hp("Resources/Image/UI/Life Blank.png", -0.1f + i * 0.1f, 0.32f));
		AttachObject(hpBg[i]);
		player->AttachChild(hpBg[i]);*/
		hps.push_back(new Hp("Resources/Image/UI/Life.png", -0.1f + i * 0.1f, 0.32f));
		AttachObject(hps[i]);
		player->AttachChild(hps[i]);
	}
	left = new UI("Resources/Image/UI/bgChoice/left.png", -4.75, 1.85);
	right = new UI("Resources/Image/UI/bgChoice/right.png", -3.9, 1.85);
	AttachObject(left);
	AttachObject(right);
	//배경 UI
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/black_big.png", "Resources/Image/UI/bgChoice/black_small.png"));
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/pink_big.png", "Resources/Image/UI/bgChoice/pink_small.png"));
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/orange_big.png", "Resources/Image/UI/bgChoice/orange_small.png"));
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/blue_big.png", "Resources/Image/UI/bgChoice/blue_small.png"));
	for (auto iter : bgUi)
		AttachObject(iter);
	
	//장애물

	for (auto iter : obstacles)
		AttachObject(iter);
	
	for (auto iter : floors) {
		AttachObject(iter);
		iter->SetTag("Floor");
	}

}

FourthGScene::~FourthGScene()
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
	for (auto iter : bgUi)
		delete iter;
}

void FourthGScene::OnUpdate()
{
	if (isPlaying) {
		currentPosX += 4 * RG2R_TimeM->GetDeltaTime();
		checkPosX += 4 * RG2R_TimeM->GetDeltaTime();
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
	
}

void FourthGScene::OnStart()
{
	bgUi[0]->isCurrentBg();
	bgUi[3]->isSideBg(-1);
	bgUi[1]->isSideBg(1);
	bgUi[2]->isNotUsed();
}

void FourthGScene::GameOver()
{
	cout << "GameOver" << endl;
	RG2R_SceneM->ChangeScene(new EndingScene((currentPosX + 3) / 4 + plusPoint + 150));
}

void FourthGScene::ChangeHp(int currentHp, int changeHp)
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

void FourthGScene::ChangeBg(int currentBG)
{
	if (currentBG == 0) {
		bgUi[0]->isCurrentBg();
		bgUi[1]->isSideBg(1);
		bgUi[2]->isNotUsed();
		bgUi[3]->isSideBg(-1);
	}
	else if (currentBG == 1) {
		bgUi[0]->isSideBg(-1);
		bgUi[1]->isCurrentBg();
		bgUi[2]->isSideBg(1);
		bgUi[3]->isNotUsed();
	}
	else if(currentBG ==2 ){
		bgUi[0]->isNotUsed();
		bgUi[1]->isSideBg(-1);
		bgUi[2]->isCurrentBg();
		bgUi[3]->isSideBg(1);
	}
	else {
		bgUi[0]->isNotUsed();
		bgUi[1]->isSideBg(1);
		bgUi[2]->isSideBg(-1);
		bgUi[3]->isCurrentBg();
	}
	currentBg = currentBG;
}
