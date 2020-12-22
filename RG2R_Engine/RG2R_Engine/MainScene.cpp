#include "stdafx.h"
#include "MainScene.h"
#include "SpriteRenderer.h"
#include "FirstGScene.h"
#include "SecondGScene.h"
#include "SpriteRenderer.h"
#include "TutorialScene.h"
#include "BoxCollider.h"
#include "ThirdGScene.h"
#include "FifthGScene.h"
MainScene::MainScene()
{
	bg = new Background("Resources/MainScene/robbyBg.png");
	AttachObject(bg);
	
	//¹öÆ°
	playBtn = CreateObject();
	playBtn->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/MainScene/playBtn.png");
	playBtn->AttachComponent<BoxCollider>()->SetAreaAuto();
	playBtn->GetComponent<Transform>()
		->SetAnchor(playBtn->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(-2.9f, 0.5f);
	playBtn->AttachComponent<Button>();
	playBtn->onClickExit = []() {RG2R_SceneM->ChangeScene(new ThirdGScene(50)); cout << "play clicked" << endl; };

	tutorialBtn = CreateObject();
	tutorialBtn->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/MainScene/tutorialBtn.png");
	tutorialBtn->AttachComponent<BoxCollider>()->SetAreaAuto();
	tutorialBtn->GetComponent<Transform>()
		->SetAnchor(tutorialBtn->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(-2.9f, -0.4f);
	tutorialBtn->AttachComponent<Button>();
	tutorialBtn->onClickEnter = []() {RG2R_SceneM->ChangeScene(new TutorialScene()); cout << "tutorial clicked" << endl; };
	exitBtn = CreateObject();
	exitBtn->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/MainScene/exitBtn.png");
	exitBtn->AttachComponent<BoxCollider>()->SetAreaAuto();
	exitBtn->GetComponent<Transform>()
		->SetAnchor(exitBtn->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(-2.9f, -1.3);
	exitBtn->AttachComponent<Button>();
	exitBtn->onClickExit = []() { cout << "exit clicked" << endl; exit(0); cout << "exit clicked" << endl; };

	
}

MainScene::~MainScene()
{
	delete bg;
	delete playBtn;
	delete tutorialBtn;
	delete exitBtn;
}



void MainScene::OnUpdate()
{
	
}
 
