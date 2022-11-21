#include "Ball.h"
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
	AddComponent<RigidBodyComponent>(Text::GetHash("Body"), InPosition, 2.0f * InRadius, 2.0f * InRadius, InRotate, InVelocity, true);
	AddComponent<BallPhysicComponent>(Text::GetHash("Physic"));
	AddComponent<SpriteRenderComponent>(Text::GetHash("Render"), Text::GetHash("Ball"));
}

Ball::~Ball()
{
}

void Ball::Update(Input& InInput, float InDeltaSeconds)
{
	GetComponent<BallPhysicComponent>(Text::GetHash("Physic"))->Tick(*World_, InDeltaSeconds);
}

void Ball::Render(Renderer& InRenderer, Camera& InCamera)
{
	GetComponent<SpriteRenderComponent>(Text::GetHash("Render"))->Tick(InRenderer, InCamera);
}
