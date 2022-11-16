#include "PlayerInputComponent.h"
#include "RigidBody.h"
#include "Player.h"
#include "GameObject.h"
#include "Input.h"

void PlayerInputComponent::Tick(Input& InInput)
{
	Player* CurrentPlayer = reinterpret_cast<Player*>(Object_);

	float Rotate = CurrentPlayer->GetRotate();

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
		Rotate = 90.0f;
	}

	if (InInput.GetKeyPressState(DownCode) == EPressState::PRESSED)
	{
		Rotate = 270.0f;
	}

	CurrentPlayer->SetRotate(Rotate);

	if (InInput.GetKeyPressState(UpCode) == EPressState::HELD ||
		InInput.GetKeyPressState(DownCode) == EPressState::HELD)
	{
		CurrentPlayer->SetCanMove(true);
	}
	else
	{
		CurrentPlayer->SetCanMove(false);
	}
}
