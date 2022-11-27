#include "Ball.h"
#include "BallInputComponent.h"
#include "BallPhysicComponent.h"
#include "SpriteRenderComponent.h"

#include <Text.hpp>
#include <RigidBodyComponent.h>

Ball::Ball(
	World* InWorld, 
	const std::size_t& InSignature, 
	const Vec2f& InPosition, 
	const float& InRadius,
	const float& InRotate,
	const float& InVelocity
) : GameObject(InWorld, InSignature)
{
	AddComponent<BallInputComponent>(Text::GetHash("Input"));
	AddComponent<RigidBodyComponent>(Text::GetHash("Body"), InPosition, 2.0f * InRadius, 2.0f * InRadius, InRotate, InVelocity, true);
	AddComponent<BallPhysicComponent>(Text::GetHash("Physic"));
	AddComponent<SpriteRenderComponent>(Text::GetHash("Render"), Text::GetHash("Ball"));

	Reset();
}

Ball::~Ball()
{
}

void Ball::Update(Input& InInput, float InDeltaSeconds)
{
	GetComponent<BallInputComponent>(Text::GetHash("Input"))->Tick(InInput);
	GetComponent<BallPhysicComponent>(Text::GetHash("Physic"))->Tick(*World_, InDeltaSeconds);
}

void Ball::Render(Renderer& InRenderer, Camera& InCamera)
{
	GetComponent<SpriteRenderComponent>(Text::GetHash("Render"))->Tick(InRenderer, InCamera);
}

void Ball::Reset()
{
	RigidBodyComponent* Body = GetComponent<RigidBodyComponent>(Text::GetHash("Body"));

	CurrentState_ = EState::WAIT;
	
	Body->SetPosition(Vec2f(0.0f));
	Body->SetRotate(0.0f);
	Body->SetCanMove(false);
}

void Ball::Start()
{
	RigidBodyComponent* Body = GetComponent<RigidBodyComponent>(Text::GetHash("Body"));

	CurrentState_ = EState::MOVE;

	float Rotate = 0.0f;
	if (Math::GenerateRandomInt<int32_t>(1, 2) == 1)
	{
		Rotate = Math::GenerateRandomFloat<float>(-45.0f, 45.0f);
	}
	else
	{
		Rotate = Math::GenerateRandomFloat<float>(135.0f, 225.0f);
	}

	Body->SetCanMove(true);
	Body->SetRotate(Rotate);
}
