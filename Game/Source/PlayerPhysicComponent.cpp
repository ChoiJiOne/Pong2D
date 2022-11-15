#include "PlayerPhysicComponent.h"
#include "GameObject.h"
#include "MathUtils.h"
#include "World.h"
#include "Body.h"

void PlayerPhysicComponent::Tick(World& InWorld, float InDeltaSeconds)
{
	Body& ObjectBody = Object_->GetBody();

	if (ObjectBody.CanMove())
	{
		Vec2f Position = ObjectBody.GetCenter();

		Position.y += InDeltaSeconds * ObjectBody.GetVelocity() * static_cast<float>(sin(MathUtils::ToRadian(ObjectBody.GetRotate())));
		Position.y = MathUtils::Clamp<float>(Position.y, 0.0f, static_cast<float>(InWorld.GetHeight()));

		ObjectBody.SetCenter(Position);
	}
}
