#include "Background.h"
#include "SpriteRenderComponent.h"

#include <World.h>
#include <Text.hpp>
#include <RigidBodyComponent.h>

Background::Background(
	World* InWorld, 
	const std::size_t& InSignature, 
	const Vec2f& InPosition, 
	const float& InWidth, 
	const float& InHeight
) : GameObject(InWorld, InSignature)
{
	AddComponent<RigidBodyComponent>(Text::GetHash("Body"), InPosition, InWidth, InHeight, 0.0f, 0.0f, false);
	AddComponent<SpriteRenderComponent>(Text::GetHash("Render"), Text::GetHash("Space"));
}

Background::~Background()
{
}

void Background::Update(Input& InInput, float InDeltaSeconds)
{
}

void Background::Render(Renderer& InRenderer, Camera& InCamera)
{
	GetComponent<SpriteRenderComponent>(Text::GetHash("Render"))->Tick(InRenderer, InCamera);
}

void Background::SetSize(const float& InWidth, const float& InHeight)
{
	RigidBodyComponent* RigidBody = GetComponent<RigidBodyComponent>(Text::GetHash("Body"));

	RigidBody->SetWidth(InWidth);
	RigidBody->SetHeight(InHeight);
}
