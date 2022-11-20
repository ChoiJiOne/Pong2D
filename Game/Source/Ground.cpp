#include "Ground.h"
#include "GroundRenderComponent.h"

#include <Text.hpp>
#include <RigidBodyComponent.h>

Ground::Ground(
	World* InWorld, 
	const std::size_t& InSignature,
	const Vec2f& InPosition, 
	const float& InWidth, 
	const float& InHeight
) : GameObject(InWorld, InSignature)
{
	AddComponent<RigidBodyComponent>(Text::GetHash("Body"), InPosition, InWidth, InHeight, 0.0f, 0.0f, false);
	AddComponent<GroundRenderComponent>(Text::GetHash("Render"), Color::White);
}

Ground::~Ground()
{
}

void Ground::Update(Input& InInput, float InDeltaSeconds)
{
}

void Ground::Render(Renderer& InRenderer, Camera& InCamera)
{
	GetComponent<GroundRenderComponent>(Text::GetHash("Render"))->Tick(InRenderer, InCamera);
}
