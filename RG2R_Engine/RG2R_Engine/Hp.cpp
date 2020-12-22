#include "stdafx.h"
#include "Hp.h"

#include "SpriteRenderer.h"
#include "Effect.h"

Hp::Hp(std::string t, float x, float y)
{
	this->texture = t;
	this->x = x;
	this->y = y;
}



Hp::~Hp()
{
}


void Hp::OnStart() {
	AttachComponent<SpriteRenderer>()
		->SetTexture(texture)->SetZ_index(2);

	
	GetTransform()->Translate(x, y);

	AttachComponent<Effect>()->PushEffectInfo(new ColorMatrixEffectInfo(Color(1, 1, 1)));
}

void Hp::MinusHp()
{
	((ColorMatrixEffectInfo*)(GetComponent<Effect>()->GetEffects()[0]))->SetColor(Color(1, 1, 1, 0));
}

void Hp::PlusHp()
{
	((ColorMatrixEffectInfo*)(GetComponent<Effect>()->GetEffects()[0]))->SetColor(Color(1, 1, 1, 1));
}
