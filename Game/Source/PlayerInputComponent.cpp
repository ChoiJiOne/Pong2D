#include "PlayerInputComponent.h"
#include "Body.h"
#include "Player.h"
#include "GameObject.h"
#include "Input.h"

void PlayerInputComponent::Tick(Input& InInput)
{
	Player* CurrentPlayer = reinterpret_cast<Player*>(Object_);

	Body& ObjectBody = Object_->GetBody();
	float Rotate = ObjectBody.GetRotate();

	EScanCode UpCode, DownCode;

	if (CurrentPlayer->GetType() == Player::EType::PLAYER1)
	{
		UpCode = EScanCode::CODE_Q;
		DownCode = EScanCode::CODE_A;
	}
	else // CurrentPlayer->GetType() == Player::EType::PLAYER2
	{
		UpCode = EScanCode::CODE_UP;
		DownCode = EScanCode::CODE_DOWN;
	}

	if (InInput.GetKeyPressState(UpCode) == EPressState::PRESSED)
	{
		Rotate = 270.0f;
	}

	if (InInput.GetKeyPressState(DownCode) == EPressState::PRESSED)
	{
		Rotate = 90.0f;
	}

	ObjectBody.SetRotate(Rotate);

	if (InInput.GetKeyPressState(UpCode) == EPressState::HELD ||
		InInput.GetKeyPressState(DownCode) == EPressState::HELD)
	{
		ObjectBody.SetCanMove(true);
	}
	else
	{
		ObjectBody.SetCanMove(false);
	}
}
