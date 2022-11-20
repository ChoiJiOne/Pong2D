#include "Ball.h"
#include "SpriteRenderComponent.h"

#include <Text.hpp>
#include <RigidBodyComponent.h>

Ball::Ball(
	World* InWorld, 
	const std::size_t& InSignature, 
	const Vec2f& InPosition, 
	const float& InRadius, 
	const float& InVelocity
) : GameObject(InWorld, InSignature)
{
	AddComponent<RigidBodyComponent>(Text::GetHash("Body"), InPosition, InRadius, 0.0f, InVelocity, false);
	AddComponent<SpriteRenderComponent>(Text::GetHash("Render"), Text::GetHash("Ball"));
}

Ball::~Ball()
{
}

void Ball::Update(Input& InInput, float InDeltaSeconds)
{
}

void Ball::Render(Renderer& InRenderer, Camera& InCamera)
{
	GetComponent<SpriteRenderComponent>(Text::GetHash("Render"))->Tick(InRenderer, InCamera);
}
