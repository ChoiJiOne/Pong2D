#include "PlayerPhysicComponent.h"
#include "GameObject.h"
#include "MathUtils.h"
#include "World.h"
#include "RigidBody.h"

void PlayerPhysicComponent::Tick(World& InWorld, float InDeltaSeconds)
{
	if (Object_->CanMove())
	{
		Vec2f Position = Object_->GetCenter();

		Position.y += InDeltaSeconds * Object_->GetVelocity() * static_cast<float>(sin(MathUtils::ToRadian(Object_->GetRotate())));

		Object_->SetCenter(Position);
	}
}
