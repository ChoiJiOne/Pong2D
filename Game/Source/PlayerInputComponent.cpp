#include "PlayerInputComponent.h"
#include "Body.h"
#include "GameObject.h"
#include "Input.h"

void PlayerInputComponent::Tick(Input& InInput)
{
	Body& ObjectBody = Object_->GetBody();
	float Rotate = ObjectBody.GetRotate();

	if (InInput.GetKeyPressState(EScanCode::CODE_UP) == EPressState::PRESSED)
	{
		Rotate = 270.0f;
	}

	if (InInput.GetKeyPressState(EScanCode::CODE_DOWN) == EPressState::PRESSED)
	{
		Rotate = 90.0f;
	}

	ObjectBody.SetRotate(Rotate);

	if (InInput.GetKeyPressState(EScanCode::CODE_UP) == EPressState::HELD ||
		InInput.GetKeyPressState(EScanCode::CODE_DOWN) == EPressState::HELD)
	{
		ObjectBody.SetCanMove(true);
	}
	else
	{
		ObjectBody.SetCanMove(false);
	}
}
