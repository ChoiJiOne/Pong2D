#include "BallPhysicComponent.h"
#include "Player.h"

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

	std::array<GameObject*, 2> Objects = {
		InWorld.GetObject(Text::GetHash("Player1")),
		InWorld.GetObject(Text::GetHash("Player2"))
	};

	for (auto Object : Objects)
	{
		Player* CurrentPlayer = reinterpret_cast<Player*>(Object);

		if (RigidBody->IsCollision(CurrentPlayer->GetComponent<RigidBodyComponent>(Text::GetHash("Body"))))
		{
			Vec2f Normal = CurrentPlayer->GetNormal();
			Vec2f Direction(
				cosf(Math::ToRadian(RigidBody->GetRotate())),
				sinf(Math::ToRadian(RigidBody->GetRotate()))
			);

			if (Normal * Direction < 0)
			{
				Vec2f Reflection = Math::Reflect(Direction, Normal);
				RigidBody->SetRotate(Math::ToDegree(atan2f(Reflection.y, Reflection.x)));
			}
		}
	}
}