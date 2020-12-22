#include "stdafx.h"
#include "UI.h"

#include "SpriteRenderer.h"


UI::UI(std::string t,float x,float y)
{
	this->texture = t;
	this->x = x;
	this->y = y;
}

UI::~UI()
{
}

void UI::OnStart()
{
	AttachComponent<SpriteRenderer>()
		->SetTexture(texture)
		->SetZ_index(3);

	GetTransform()->SetIsRelative(false);

	GetTransform()->Translate(x, y);
}
