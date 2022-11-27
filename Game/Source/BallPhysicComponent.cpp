#include "BallPhysicComponent.h"
#include "Ball.h"
#include "Player.h"

#include <GameObject.h>
#include <Math.hpp>
#include <World.h>
#include <RigidBodyComponent.h>

void BallPhysicComponent::Tick(World& InWorld, float InDeltaSeconds)
{
	Move(InDeltaSeconds);
	CheckToPlayerCollision(InWorld);
	CheckToWallCollision(InWorld);
}

void BallPhysicComponent::Move(float InDeltaSeconds)
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

void BallPhysicComponent::CheckToPlayerCollision(World& InWorld)
{
	RigidBodyComponent* RigidBody = GetGameObject()->GetComponent<RigidBodyComponent>(Text::GetHash("Body"));

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

void BallPhysicComponent::CheckToWallCollision(World& InWorld)
{
	RigidBodyComponent* RigidBody = GetGameObject()->GetComponent<RigidBodyComponent>(Text::GetHash("Body"));

	std::array<RigidBodyComponent*, 2> VerticalWalls = {
		InWorld.GetObject(Text::GetHash("Ground"))->GetComponent<RigidBodyComponent>(Text::GetHash("TopWall")),
		InWorld.GetObject(Text::GetHash("Ground"))->GetComponent<RigidBodyComponent>(Text::GetHash("BottomWall"))
	};

	for (auto Wall : VerticalWalls)
	{
		if (RigidBody->IsCollision(Wall))
		{
			Vec2f Normal(
				cosf(Math::ToRadian(Wall->GetRotate())),
				sinf(Math::ToRadian(Wall->GetRotate()))
			);

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

	std::array<RigidBodyComponent*, 2> HorizonWalls = {
		InWorld.GetObject(Text::GetHash("Ground"))->GetComponent<RigidBodyComponent>(Text::GetHash("LeftWall")),
		InWorld.GetObject(Text::GetHash("Ground"))->GetComponent<RigidBodyComponent>(Text::GetHash("RightWall"))
	};

	for (auto Wall : HorizonWalls)
	{
		if (RigidBody->IsCollision(Wall))
		{
			Ball* BallObject = reinterpret_cast<Ball*>(GetGameObject());
			BallObject->Reset();
		}
	}
}
