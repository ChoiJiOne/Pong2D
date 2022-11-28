#include "BallPhysicComponent.h"
#include "Ball.h"
#include "CollisionAudioComponent.h"
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
		Player* PlayerObject = reinterpret_cast<Player*>(Object);
		RigidBodyComponent* PlayerBody = PlayerObject->GetComponent<RigidBodyComponent>(Text::GetHash("Body"));

		if (RigidBody->IsCollision(PlayerBody))
		{
			Vec2f Normal = PlayerObject->GetNormal();
			Vec2f Direction(cosf(Math::ToRadian(RigidBody->GetRotate())), sinf(Math::ToRadian(RigidBody->GetRotate())));

			if (Math::Dot(Normal, Direction) < 0.0f)
			{
				Vec2f Reflection = Math::Reflect(Direction, Normal);
				RigidBody->SetRotate(Math::ToDegree(atan2f(Reflection.y, Reflection.x)));

				GetGameObject()->GetComponent<CollisionAudioComponent>(Text::GetHash("Audio"))->SetDetectCollision(true);
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
			Vec2f Normal(cosf(Math::ToRadian(Wall->GetRotate())), sinf(Math::ToRadian(Wall->GetRotate())));
			Vec2f Direction(cosf(Math::ToRadian(RigidBody->GetRotate())), sinf(Math::ToRadian(RigidBody->GetRotate())));

			if (Math::Dot(Normal, Direction) < 0.0f)
			{
				Vec2f Reflection = Math::Reflect(Direction, Normal);
				RigidBody->SetRotate(Math::ToDegree(atan2f(Reflection.y, Reflection.x)));

				GetGameObject()->GetComponent<CollisionAudioComponent>(Text::GetHash("Audio"))->SetDetectCollision(true);
			}
		}
	}

	std::array<RigidBodyComponent*, 2> HorizonWalls = {
		InWorld.GetObject(Text::GetHash("Ground"))->GetComponent<RigidBodyComponent>(Text::GetHash("LeftWall")),
		InWorld.GetObject(Text::GetHash("Ground"))->GetComponent<RigidBodyComponent>(Text::GetHash("RightWall"))
	};

	RigidBodyComponent* LeftWall = InWorld.GetObject(Text::GetHash("Ground"))->GetComponent<RigidBodyComponent>(Text::GetHash("LeftWall"));
	if (RigidBody->IsCollision(LeftWall))
	{
		Player* Player2 = reinterpret_cast<Player*>(InWorld.GetObject(Text::GetHash("Player2")));
		Player2->SetScore(Player2->GetScore() + 1);

		Ball* BallObject = reinterpret_cast<Ball*>(GetGameObject());
		BallObject->Reset();

		GetGameObject()->GetComponent<CollisionAudioComponent>(Text::GetHash("Audio"))->SetDetectCollision(true);
	}

	RigidBodyComponent* RightWall = InWorld.GetObject(Text::GetHash("Ground"))->GetComponent<RigidBodyComponent>(Text::GetHash("RightWall"));
	if (RigidBody->IsCollision(RightWall))
	{
		Player* Player1 = reinterpret_cast<Player*>(InWorld.GetObject(Text::GetHash("Player1")));
		Player1->SetScore(Player1->GetScore() + 1);

		Ball* BallObject = reinterpret_cast<Ball*>(GetGameObject());
		BallObject->Reset();

		GetGameObject()->GetComponent<CollisionAudioComponent>(Text::GetHash("Audio"))->SetDetectCollision(true);
	}
}
