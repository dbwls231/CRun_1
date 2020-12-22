#include "stdafx.h"
#include "Obstacle.h"

#include "SpriteRenderer.h"
#include "Effect.h"

Obstacle::Obstacle(int colorIndex, std::string texture, float x, float y)
	:texture(texture),x(x),y(y)
{
	SetColorIndex(colorIndex);
}

Obstacle::~Obstacle()
{
}

void Obstacle::OnStart()
{

	AttachComponent<SpriteRenderer>()
		->SetTexture(texture)
		->SetZ_index(-1);



	boxcollider = AttachComponent<BoxCollider>();
	boxcollider->SetAreaAuto();

	rigidbody = AttachComponent<Rigidbody>();

	GetTransform()
		->SetAnchor(GetComponent<SpriteRenderer>()
			->GetRealArea().GetCenter());

	GetTransform()->Translate(x, y);


	AttachComponent<Effect>()->PushEffectInfo(new ColorMatrixEffectInfo(Color(1, 1, 1,1)));

	

}

