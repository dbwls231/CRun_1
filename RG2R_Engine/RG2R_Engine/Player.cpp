#include "stdafx.h"
#include "Player.h"

#include "Engine.h"
#include "SpriteRenderer.h"
#include "TimeManager.h"

#include "PlayScene.h"
#include "Effect.h"
#include "FirstGScene.h"
#include "SecondGScene.h"
#include "ThirdGScene.h"
#include "FourthGScene.h"
#include "FifthGScene.h"


Player::Player(int sceneN) :hp(3),currentYpower(0),isGround(false),isJump(false),isSecondJump(false),isSlide(false),isShieldOn(false),shieldTime(0),currentScene(sceneN){
	anim_run.push_back("Resources/Image/Player/run/11.png");
	anim_run.push_back("Resources/Image/Player/run/22.png");
	anim_run.push_back("Resources/Image/Player/run/33.png");
	anim_run.push_back("Resources/Image/Player/run/44.png");
}



Player::~Player() {
}


void Player::OnStart()
{


	AttachComponent<SpriteRenderer>()
		->SetTexture("Resources/Image/Player/run/11.png")
		->SetZ_index(2);


	boxcollider = AttachComponent<BoxCollider>();
	boxcollider->SetAreaAuto();

	rigidbody = AttachComponent<Rigidbody>();

	GetTransform()->SetAnchor(GetComponent<SpriteRenderer>()->GetRealArea().GetCenter());

	GetTransform()->SetPos(-3, 1);

	currentPosX = -3;

	AttachComponent<Effect>()->PushEffectInfo(new ColorMatrixEffectInfo(Color(1, 1, 1)));

	//GetTransform()->SetScale(1, 1);
}




void Player::OnUpdate() {
	if (isPlaying) {
		Movement();
		AnimationMg();
		ShieldMg();
		ChangeBg();
	}
	
}





void Player::Movement()
{
	if (GetTransform()->GetPos().y <= -1.6&&!isSlide) {
		GetTransform()->SetPosY(-1.6);
		isGround = true;
		isJump = false;
		isSecondJump = false;
		boxcollider->SetHeightSize(0.9);
		boxcollider->SetWidthSize(0.5);
		rigidbody->SetForce(0, 0);
	}
	else if (isSlide) {
		
		GetTransform()->SetPosY(-2);
		rigidbody->SetForce(0, 0);
	}
	else if (!isGround) {
		rigidbody->AddForce(0, -0.9);
	}

	if (isGround && RG2R_InputM->GetKeyState(KeyCode::KEY_LSHIFT) == KeyState::KEYSTATE_ENTER) {
		isSlide = true;
		cout << "Slide" << endl;
	}
	else if (RG2R_InputM->GetKeyState(KeyCode::KEY_LSHIFT) == KeyState::KEYSTATE_EXIT) {
		isSlide = false;
	}
	if (isGround&&!isJump&&!isSecondJump) { //���� ������
		if (RG2R_InputM->GetKeyState(KeyCode::KEY_SPACE) == KeyState::KEYSTATE_ENTER) {
			rigidbody->AddForce(0, 22);
			isJump = true;
			isGround = false;
			cout << "Jump" << endl;
		}
	}
	else if (isJump && !isSecondJump) { //�������̰� �ι�° ���� �ƴҶ�
		if (RG2R_InputM->GetKeyState(KeyCode::KEY_SPACE) == KeyState::KEYSTATE_ENTER) {
			rigidbody->SetForce(0, 15);
			isSecondJump = true;
		}
	}
	
}

void Player::AnimationMg()
{
	//�޸���
	if (isGround&&isPlaying) {
		anim_timeCheck += RG2R_TimeM->GetDeltaTime();
		if (anim_timeCheck >0.05 ) {
			GetComponent<SpriteRenderer>()
				->SetTexture(anim_run[currentFrame]);
			currentFrame++;
			if (currentFrame == 4)
				currentFrame = 0;
			anim_timeCheck = 0;
		}
	}
	//����
	else if (isJump) {
		GetComponent<SpriteRenderer>()
			->SetTexture("Resources/Image/Player/jump/up.png");
		boxcollider->SetHeightSize(0.85);
		boxcollider->SetWidthSize(0.5);
	}
	//�����̵�
	if (isSlide) {
		GetComponent<SpriteRenderer>()
			->SetTexture("Resources/Image/Player/slide/1.png");
		boxcollider->SetHeightSize(0.7);
		boxcollider->SetWidthSize(1.3);
	}
}

void Player::SetIsPlaying(bool b)
{
	this->isPlaying = b;
}

void Player::OnCollisionEnter(CollisionInfo* collision)
{
	if (!collision->object->GetTag().compare("Floor") && !isGround&&collision->object->GetColorIndex() != currentBg) {
		CheckGround();
		boxcollider->SetHeightSize(0.85);
		boxcollider->SetWidthSize(0.5);
	}	
}

void Player::OnCollisionStay(CollisionInfo* collision)
{	
	
	//���� �����̶� �浹�� ������Ʈ�� ���� ���� �ʰ� �������°� �ƴҶ�
	if (collision->object->GetColorIndex() != currentBg &&!isShieldOn&& collision->object->GetTag().compare("Floor"))
	{
		cout << "��ֹ���: " << collision->object->GetColorIndex() << ", ����: " << currentBg << endl;
		PlayerShield();
		if (currentScene == 0)
			dynamic_cast<FirstGScene*>(RG2R_SceneM->GetScene())->ChangeHp(hp, -1);
		else if (currentScene == 1)
			dynamic_cast<SecondGScene*>(RG2R_SceneM->GetScene())->ChangeHp(hp, -1);
		else if(currentScene==2)
			dynamic_cast<ThirdGScene*>(RG2R_SceneM->GetScene())->ChangeHp(hp, -1);
		else if(currentScene==4)
			dynamic_cast<FifthGScene*>(RG2R_SceneM->GetScene())->ChangeHp(hp, -1);
		hp--;
	}
}

void Player::OnCollisionExit(CollisionInfo* collision)
{
	//�ٴ��̶� �������� ���� ���� �����϶� falling
	if (!collision->object->GetTag().compare("Floor") && isGround) {
			isGround = false; 
			cout << "falling" << endl;
		}
}


void Player::CheckGround()
{
	if (!isGround) { //���� ���� ������
		cout << "isGround" << endl;
		isGround = true; //���� ���� true
		isJump = false;
		isSecondJump = false;  //���� �� �� false
		rigidbody->SetForce(0, 0);
	}
}




void Player::PlayerShield()
{
	isShieldOn = true;
	cout << "isShield On" << endl;
}

void Player::ShieldMg()
{
	if (isShieldOn) {
		if (shieldTime == 0)
			((ColorMatrixEffectInfo*)(GetComponent<Effect>()->GetEffects()[0]))->SetColor(Color(3, 1, 1, 0.7f));
		((ColorMatrixEffectInfo*)(GetComponent<Effect>()->GetEffects()[0]))->SetColor(((ColorMatrixEffectInfo*)(GetComponent<Effect>()->GetEffects()[0]))->GetColor() + Color(-0.015f, 0, 0, 0));
		shieldTime += RG2R_TimeM->GetDeltaTime();
	}
	if (shieldTime > 1 && isShieldOn == true) {
		isShieldOn = false;
		shieldTime = 0;
		((ColorMatrixEffectInfo*)(GetComponent<Effect>()->GetEffects()[0]))->SetColor(Color(1, 1, 1, 1));
		cout << "shield off" << endl;
	}
}

void Player::ChangeBg()
{
	if (RG2R_InputM->GetKeyState(KeyCode::KEY_RIGHT) == KeyState::KEYSTATE_ENTER) {
			currentBg++;
			if (currentBg == currentScene + 1)
				currentBg = 0;
			if (currentScene == 1)
				dynamic_cast<SecondGScene*>(RG2R_SceneM->GetScene())->ChangeBg(currentBg);
			else if(currentScene==2)
				dynamic_cast<ThirdGScene*>(RG2R_SceneM->GetScene())->ChangeBg(currentBg);
			else if(currentScene==4)
				dynamic_cast<FifthGScene*>(RG2R_SceneM->GetScene())->ChangeBg(currentBg);

	}
	else if (RG2R_InputM->GetKeyState(KeyCode::KEY_LEFT) == KeyState::KEYSTATE_ENTER) {
			currentBg--;
			if (currentBg == -1)
				currentBg = currentScene;
			if (currentScene == 1)
				dynamic_cast<SecondGScene*>(RG2R_SceneM->GetScene())->ChangeBg(currentBg);
			else if (currentScene == 2)
				dynamic_cast<ThirdGScene*>(RG2R_SceneM->GetScene())->ChangeBg(currentBg);
			else if (currentScene == 4)
				dynamic_cast<FifthGScene*>(RG2R_SceneM->GetScene())->ChangeBg(currentBg);
	}
	
}




