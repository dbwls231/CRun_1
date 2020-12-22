#include "stdafx.h"
#include "BlackOb.h"

#include "SpriteRenderer.h"

BlackOb::BlackOb(std::string texture, float x, float y)
{
	this->SetTag("Black");
	AttachComponent<SpriteRenderer>()
		->SetTexture(texture);

	boxcollider = AttachComponent<BoxCollider>();

	rigidbody = AttachComponent<Rigidbody>();

	GetTransform()
		->SetAnchor(GetComponent<SpriteRenderer>()
			->GetRealArea().GetCenter());

	GetTransform()->Translate(x,y); //장애물에 따라서 다르게 배치하기
}

BlackOb::~BlackOb()
{
}
