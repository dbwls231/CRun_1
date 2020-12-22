#include "stdafx.h"
#include "Black.h"

#include "SpriteRenderer.h"

Black::Black() {
	this->SetTag("Black");
	AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/Image/MapObject/Obstacle/Black/triangle_big.png");

	boxcollider = AttachComponent<BoxCollider>();
	boxcollider->OnStart();

	rigidbody = AttachComponent<Rigidbody>();

	GetTransform()
		->SetAnchor(GetComponent<SpriteRenderer>()
			->GetRealArea().GetCenter());

	GetTransform()->Translate(1, -1);

}

Black::~Black()
{
}
