#include "stdafx.h"
#include "PlayScene.h"

#include "Engine.h"
#include "SpriteRenderer.h"

PlayScene::PlayScene():currentStage(0),currentPoint(0),startTime(0),currentBG(0)
{
	
	//배경
	bg.push_back(new Background("Resources/Image/Background/Circle/gray.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/pink.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/orange.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/blue.png"));
	bg.push_back(new Background("Resources/Image/Background/Circle/purple.png"));

	player = new Player(0);

	for (auto _bg : bg) {
		AttachObject(_bg);
		_bg->GetTransform()->SetScale(0, 0);
		player->AttachChild(_bg);
	}

	bg[currentBG]->GetTransform()->SetScale(4, 4);

	AttachObject(player);

	//바닥
	//floors.push_back(new Obstacle(0, "Resources/Image/AllFloor.png", 581.73f, -2.5));

	floors.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Floor Magic.png", 124.10, -1.03));
	floors.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Floor Magic.png", 186.05, -0.83));
	floors.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Floor Magic.png", 188.47, -0.83));

	for (int i = 0; i < 20; i++) {
		floors.push_back(new Obstacle(0, "Resources/Image/MapObject/Floor.png", -5.25 + 10.43 * i, -2.5));
	}

	for (auto _floors : floors) {
		AttachObject(_floors);
		(_floors)->SetTag("Floor");
	}


	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block1.png", 14.17, -1.2));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 23.3, 0.51));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block5.png", 28.8, -1.198));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block4.png", 32.72, -1.198));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block2.png", 36.5, -1.2));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Double Box1.png", 41.9, 0.7));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 46.9, 0.516));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block4.png", 54.03, -1.198));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block5.png", 55.16, -1.2));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Triangle Up-big.png", 60.6, 0.619));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Triangle Down-small.png", 72.14, -1.225));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 84.44, 0.51));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 87.47, 0.51));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 91.54, 0.516));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Wall.png", 106.41, 0.27));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block1.png", 112.02, -1.27));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Box.png", 112.02, -0.07));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block1.png", 112.02, 1.13));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Double Box1.png", 119.39, -0.07));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/triangle_big.png", 126.86, -0.66));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 141.26, 0.52));
	obstacles.push_back(new Obstacle(1, "Resources/Image/MapObject/Obstacle/Pink/Color Box.png", 141.26, -1.285));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle2.png", 147.89, 0.52));
	obstacles.push_back(new Obstacle(2, "Resources/Image/MapObject/Obstacle/Orange/Color Box.png", 147.89, -1.285));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block4.png", 155.39, -1.20));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Triangle Up-small.png", 158.28, 1.24));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Triangle Up-small.png", 165.20, 1.24));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 171.47, 0.51));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Block4.png", 175.17, -1.198));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Obstacle1.png", 178.48, 0.51));
	obstacles.push_back(new Obstacle(0, "Resources/Image/MapObject/Obstacle/Black/Thorn Down.png", 187.5, -1.64));
	

	for (auto iter : obstacles)
		AttachObject(iter);
	
	//배경 UI
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/black_big.png", "Resources/Image/UI/bgChoice/black_small.png"));
	
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/pink_big.png", "Resources/Image/UI/bgChoice/pink_small.png"));
	
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/orange_big.png", "Resources/Image/UI/bgChoice/orange_small.png"));
	
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/blue_big.png", "Resources/Image/UI/bgChoice/blue_small.png"));
	
	bgUi.push_back(new BgUI("Resources/Image/UI/bgChoice/purple_big.png", "Resources/Image/UI/bgChoice/purple_small.png"));
	
	blackBg = new BgUI("Resources/Image/UI/bgChoice/black_big.png", "Resources/Image/UI/bgChoice/black_small.png");
	AttachObject(blackBg);
	pinkBg = new BgUI("Resources/Image/UI/bgChoice/pink_big.png", "Resources/Image/UI/bgChoice/pink_small.png");
	AttachObject(pinkBg);

	for (auto iter : bgUi)
		AttachObject(iter);


	//Player Life
	for (int i = 0; i < 3; i++) {
		hpBg.push_back(new Hp("Resources/Image/UI/Life Blank.png", -0.1f+i*0.1f ,0.32f));
		AttachObject(hpBg[i]);
		player->AttachChild(hpBg[i]);
		hps.push_back(new Hp("Resources/Image/UI/Life.png", -0.1f + i * 0.1f,0.32f));
		AttachObject(hps[i]);
		player->AttachChild(hps[i]);
	}
	
	//화살표 UI
	left = new UI("Resources/Image/UI/bgChoice/left.png", -4.75, 1.85);
	
	right = new UI("Resources/Image/UI/bgChoice/right.png", -3.9, 1.85);
	
	AttachObject(left);
	AttachObject(right);
	
}



PlayScene::~PlayScene()
{
}




void PlayScene::OnUpdate()
{
	currentPoint += RG2R_TimeM->GetDeltaTime();
	GetMainCamera()->Translate(4 * RG2R_TimeM->GetDeltaTime(), 0);
	ChangeBG();
	if (currentPoint>1&&currentStage==0) {
		cout << "stage:1" << endl;
		currentStage = 1;
		PlusBG(1);
	}
	else if(currentPoint > 2 && currentStage == 1) {
		cout << "stage:2" << endl;
		currentStage = 2;
		PlusBG(2);
	}
	else if (currentPoint > 3 && currentStage == 2) {
		cout << "stage:3" << endl;
		currentStage = 3;
		PlusBG(3);
	}
	else if (currentPoint > 4 && currentStage == 3) {
		cout << "stage:4" << endl;
		currentStage = 4;
		PlusBG(4);
	}
	
	if (RG2R_InputM->GetKeyState(KeyCode::KEY_ESCAPE) == KeyState::KEYSTATE_ENTER) 
	{
		system("PAUSE");
	}
	
}

void PlayScene::OnStart() {
	bgUi[0]->isCurrentBg();
}

void PlayScene::PlusBG(int k) //시간 지났을 때 색 +
{
	if (k == 1) {

		bgUi[1]->isSideBg(1);
		pinkBg->isSideBg(-1);
	}
	else {
		if (k == 2) {
			pinkBg->isNotUsed();
			blackBg->isNotUsed();
		}
		if (currentBG == 0) { //지금 색이 회색
			if(k!=2)
				bgUi[currentStage - 1]->isNotUsed(); //원래 제일 마지막 색 삭제
			bgUi[currentStage]->isSideBg(-1);
		}
		else if (currentBG == currentStage - 1) { //원래 제일 마지막 색이었을때
			if(k!=2)
				bgUi[0]->isNotUsed(); //회색 삭제
			bgUi[currentStage]->isSideBg(1);
		}
	}
}



void PlayScene::ChangeBG() { //현재 배경 색 바꾸기
	if (currentStage == 1) {
		if (RG2R_InputM->GetKeyState(KeyCode::KEY_RIGHT) == KeyState::KEYSTATE_ENTER or RG2R_InputM->GetKeyState(KeyCode::KEY_LEFT) == KeyState::KEYSTATE_ENTER) {
			if (currentBG == 0) {
				currentBG = 1;
				bgUi[0]->isSideBg(-1);
				blackBg->isSideBg(1);
				pinkBg->isNotUsed();
			}
			else {
				currentBG = 0;
				bgUi[1]->isSideBg(1);
				pinkBg->isSideBg(-1);
				blackBg->isNotUsed();
			}
			bgUi[currentBG]->isCurrentBg();
		}
	}
	else if (currentStage != 0) {
		if (RG2R_InputM->GetKeyState(KeyCode::KEY_RIGHT) == KeyState::KEYSTATE_ENTER) {
			for (int i = 0; i < currentStage; i++) {
				bgUi[i]->isNotUsed();
			}
			if (currentBG == currentStage) //현재 색이 지금 스테이지 끝일때
			{
				currentBG = 0;
				bgUi[currentStage]->isSideBg(-1);
				bgUi[1]->isSideBg(1);
			}
			else
			{
				currentBG++; //그 다음색으로
				bgUi[currentBG - 1]->isSideBg(-1);
				if (currentBG == currentStage)
					bgUi[0]->isSideBg(1);
				else {
					bgUi[currentBG + 1]->isSideBg(1);
				}
			}
			bgUi[currentBG]->isCurrentBg();
		}
		if (RG2R_InputM->GetKeyState(KeyCode::KEY_LEFT) == KeyState::KEYSTATE_ENTER) {
			for (int i = 0; i < currentStage; i++) {
				bgUi[i]->isNotUsed();
			}
			if (currentBG == 0) //현재 색이 첫번째
			{
				currentBG = currentStage;
				bgUi[0]->isSideBg(1);
				bgUi[currentBG - 1]->isSideBg(-1);
			}
			else
			{
				--currentBG; //그 전 색으로
				if (currentBG == 0) {
					bgUi[currentStage]->isSideBg(-1);
					bgUi[1]->isSideBg(1);
				}
				else {
					bgUi[currentBG + 1]->isSideBg(1);
					bgUi[currentBG - 1]->isSideBg(-1);
				}
				
			}

			bgUi[currentBG]->isCurrentBg();
		}
	}


	for (int i = 0; i <= 4; i++) {
		if (i != currentBG && bg[i]->GetTransform()->GetScale().x >= 0.0f) {
			bg[i]->GetTransform()->SetScale(bg[i]->GetTransform()->GetScale() - Vec2F(8, 8) * RG2R_TimeM->GetDeltaTime());

			if (bg[i]->GetTransform()->GetScale().x < 0.0f)
				bg[i]->GetTransform()->SetScale(0, 0);
		}

	}
	if (bg[currentBG]->GetTransform()->GetScale().x < 4)
		bg[currentBG]->GetTransform()->SetScale(bg[currentBG]->GetTransform()->GetScale().x + 8 * RG2R_TimeM->GetDeltaTime(), bg[currentBG]->GetTransform()->GetScale().y + 8 * RG2R_TimeM->GetDeltaTime());

}

void PlayScene::GameOver()
{
	cout << "GameOver" << endl;
	RG2R_SceneM->ChangeScene(new EndingScene(currentPoint));
}

void PlayScene::ChangeHp(int currentHp, int changeHp)
{
	if (changeHp == -1) {
		hps[currentHp]->MinusHp();
	}
	if (changeHp == 1) {
		if (currentHp == 3) //만약에 이미 hp가 3이면 점수에 +
			currentPoint += 1000; //나중에 수정 
		hps[currentHp]->PlusHp();
	}
}

int PlayScene::GetCurrentBG()
{
	if (currentBG == 0) {
		return -1;
	}
	return currentBG;
}

