#include "stdafx.h"
#include "TutorialScene.h"
#include "SpriteRenderer.h"
#include "Engine.h"
#include "MainScene.h"
#include "BoxCollider.h"

TutorialScene::TutorialScene()
{
	tutorial = CreateObject();
	tutorial->AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/Image/tutorial.png")
		->SetZ_index(1);
	tutorial->AttachComponent<BoxCollider>()->SetAreaAuto();
	tutorial->AttachComponent<Transform>()
		->SetAnchor(tutorial->GetComponent<SpriteRenderer>()->GetRealArea().GetCenter())
		->SetPos(0, 0)
		->SetIsRelative(false);
}

TutorialScene::~TutorialScene()
{
	delete tutorial;
}

void TutorialScene::OnUpdate()
{
	if (RG2R_InputM->GetKeyState(KeyCode::KEY_ESCAPE) == KeyState::KEYSTATE_ENTER) {
		RG2R_SceneM->ChangeScene(new MainScene());
	}
}
