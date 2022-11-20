#include "PlayerPhysicComponent.h"

#include <GameObject.h>
#include <Math.hpp>
#include <World.h>
#include <RigidBodyComponent.h>

void PlayerPhysicComponent::Tick(World& InWorld, float InDeltaSeconds)
{
	RigidBodyComponent* RigidBody = GetGameObject()->GetComponent<RigidBodyComponent>(Text::GetHash("Body"));

	if (RigidBody->CanMove())
	{
		Vec2f Position = RigidBody->GetPosition();

		Position.y += InDeltaSeconds * RigidBody->GetVelocity() * sinf(Math::ToRadian(RigidBody->GetRotate()));

		RigidBody->SetPosition(Position);
	}
}