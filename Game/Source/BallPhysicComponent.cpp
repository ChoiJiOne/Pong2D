#include "BallPhysicComponent.h"

#include <GameObject.h>
#include <Math.hpp>
#include <World.h>
#include <RigidBodyComponent.h>

void BallPhysicComponent::Tick(World& InWorld, float InDeltaSeconds)
{
	RigidBodyComponent* RigidBody = GetGameObject()->GetComponent<RigidBodyComponent>(Text::GetHash("Body"));

	if (RigidBody->CanMove())
	{
		float CosTheta = cosf(Math::ToRadian(RigidBody->GetRotate()));
		float SinTheta = sinf(Math::ToRadian(RigidBody->GetRotate()));

		Vec2f Position = RigidBody->GetPosition();

		Position.x += (CosTheta * RigidBody->GetVelocity() * InDeltaSeconds);
		Position.y += (SinTheta * RigidBody->GetVelocity() * InDeltaSeconds);

		RigidBody->SetPosition(Position);
	}
}