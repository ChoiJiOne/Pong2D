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

	GameObject* GroundObject = InWorld.GetObject(Text::GetHash("Ground"));
	RigidBodyComponent* GroundRigidBody = GroundObject->GetComponent<RigidBodyComponent>(Text::GetHash("Body"));
	RigidBodyComponent* TopWall = GroundObject->GetComponent<RigidBodyComponent>(Text::GetHash("TopWall"));
	RigidBodyComponent* BottomWall = GroundObject->GetComponent<RigidBodyComponent>(Text::GetHash("BottomWall"));

	if (RigidBody->IsCollision(TopWall) || RigidBody->IsCollision(BottomWall))
	{
		Vec2f Position = RigidBody->GetPosition();

		float Length = GroundRigidBody->GetHeight() / 2.0f - RigidBody->GetHeight() / 2.0f;
		Position.y = Position.y > 0 ? Length : -Length;

		RigidBody->SetPosition(Position);
	}
}