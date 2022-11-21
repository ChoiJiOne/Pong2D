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

	RigidBodyComponent* GroundRigidBody = InWorld.GetObject(Text::GetHash("Ground"))->GetComponent<RigidBodyComponent>(Text::GetHash("Body"));
//	if (GroundRigidBody->IsCollision(RigidBody))
	if (!RigidBody->IsOutter(GroundRigidBody))
	{
		Vec2f Position = RigidBody->GetPosition();

		float Length = GroundRigidBody->GetHeight() / 2.0f - RigidBody->GetHeight() / 2.0f;
		Position.y = Position.y > 0 ? Length : -Length;

		RigidBody->SetPosition(Position);
	}
}