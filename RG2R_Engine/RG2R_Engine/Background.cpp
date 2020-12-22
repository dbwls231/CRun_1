#include "stdafx.h"
#include "Background.h"

#include "SpriteRenderer.h"

Background::Background(std::string texture)
{
	AttachComponent<SpriteRenderer>()
		->SetTexture(texture)
		->SetZ_index(-4);

	GetTransform()->SetAnchor(GetComponent<SpriteRenderer>()->GetRealArea().GetCenter());
}

Background::~Background()
{
}
