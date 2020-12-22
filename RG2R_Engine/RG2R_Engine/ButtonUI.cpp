#include "stdafx.h"
#include "ButtonUI.h"
#include "SpriteRenderer.h"

ButtonUI::ButtonUI(std::string t, float x, float y)
{
	this->texture = t;
	this->x = x;
	this->y = y;
}

ButtonUI::~ButtonUI()
{
	
}

void ButtonUI::OnStart()
{
	AttachComponent<SpriteRenderer>()
		->SetTexture(texture);

	GetTransform()->SetIsRelative(false);

	boxcollider = AttachComponent<BoxCollider>();

	rigidbody = AttachComponent<Rigidbody>();

	GetTransform()
		->SetAnchor(GetComponent<SpriteRenderer>()
			->GetRealArea().GetCenter());

	GetTransform()->Translate(x, y);
	
	
}


