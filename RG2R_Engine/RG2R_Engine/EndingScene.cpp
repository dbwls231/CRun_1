#include "stdafx.h"
#include "EndingScene.h"
#include "SpriteRenderer.h"

#include "FirstGScene.h"
#include "SecondGScene.h"
EndingScene::EndingScene(float p)
{
	bg = new Background("Resources/EndingScene/endingBg.png");
	AttachObject(bg);

	if (p < 10) {
		text_posX = -0.54f;
	}
	else if (p < 100) {
		text_posX = -0.72;
	}
	else if (p < 1000) {
		text_posX = -0.9;
	}
	else if (p < 10000) {
		text_posX = -1.08;
	}
	if (p == 100000) {
		text_posX = -1.44;
	}
	

	Object* point = CreateObject();	
	point->AttachComponent<TextRenderer>()
		->SetText(to_string((int)p * 100))
		->SetTextColor(Color(1, 1, 1, 1))
		->SetSize(100)
		->SetFontFamily(L"¾çÀç²É°ÔÃ¼Med");
	point->AttachComponent<Transform>()
		->SetPos(text_posX,0);

	


	mainBtn = CreateObject();
	mainBtn->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/EndingScene/mainBtn.png");
	mainBtn->AttachComponent<BoxCollider>()->SetAreaAuto();
	mainBtn->GetComponent<Transform>()
		->SetAnchor(mainBtn->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(-1, -1.1f);
	mainBtn->AttachComponent<Button>();
	mainBtn->onClickExit = []() {RG2R_SceneM->ChangeScene(new MainScene()); cout << "main clicked" << endl; };


	replayBtn = CreateObject();
	replayBtn->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/EndingScene/replayBtn.png");
	replayBtn->AttachComponent<BoxCollider>()->SetAreaAuto();
	replayBtn->GetComponent<Transform>()
		->SetAnchor(replayBtn->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(1, -1.1f);
	replayBtn->AttachComponent<Button>();
	replayBtn->onClickExit = []() {RG2R_SceneM->ChangeScene(new FirstGScene()); cout << "replay clicked" << endl; };

}

EndingScene::~EndingScene()
{
	delete bg;
	delete replayBtn;
	delete mainBtn;
}
