#include "stdafx.h"
#include "BgUI.h"
#include "SpriteRenderer.h"
#include "Effect.h"

BgUI::BgUI(std::string b, std::string s)
{
	this->bigBg = b;
	this->smallBg = s;
}

BgUI::~BgUI()
{
}

void BgUI::OnStart()
{
	AttachComponent<SpriteRenderer>()
		->SetTexture(smallBg)
		->SetZ_index(3);

	GetTransform()->Translate(-5, 2.2);

	GetTransform()->SetIsRelative(false);

	AttachComponent<Effect>()->PushEffectInfo(new ColorMatrixEffectInfo(Color(1, 1, 1,0)));
	
}

void BgUI::isCurrentBg()
{
	GetComponent<SpriteRenderer>()
		->SetTexture(bigBg);
	GetTransform()->SetPos(-4.5, 2.2);//수정 해야됨
	((ColorMatrixEffectInfo*)(GetComponent<Effect>()->GetEffects()[0]))->SetColor(Color(1, 1, 1, 1));
}

void BgUI::isSideBg(int k) // -1이면 왼쪽 1이면 오른쪽
{
	GetComponent<SpriteRenderer>()
		->SetTexture(smallBg);
	GetTransform()->SetPos(-4.4+ 0.7*k, 2.1); //수정 해야됨
	((ColorMatrixEffectInfo*)(GetComponent<Effect>()->GetEffects()[0]))->SetColor(Color(1, 1, 1, 1));
}

void BgUI::isNotUsed()
{
	((ColorMatrixEffectInfo*)(GetComponent<Effect>()->GetEffects()[0]))->SetColor(Color(1, 1, 1, 0));
}



