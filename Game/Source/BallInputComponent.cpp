#include "BallInputComponent.h"
#include "Ball.h"

#include <Input.h>

void BallInputComponent::Tick(Input& InInput)
{
	Ball* BallObject = reinterpret_cast<Ball*>(GetGameObject());

	if (InInput.GetKeyPressState(EKeyCode::CODE_SPACE) == EPressState::PRESSED && BallObject->GetCurrentState() == Ball::EState::WAIT)
	{
		BallObject->Start();
	}
}
