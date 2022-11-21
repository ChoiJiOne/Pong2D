#include "Ground.h"
#include "GroundRenderComponent.h"

#include <Text.hpp>
#include <RigidBodyComponent.h>

Ground::Ground(
	World* InWorld, 
	const std::size_t& InSignature,
	const Vec2f& InPosition, 
	const float& InWidth, 
	const float& InHeight,
	const float& InWallSize
) : GameObject(InWorld, InSignature)
{
	Vec2f TopWallPosition(InPosition.x, +(InHeight + InWallSize) / 2.0f);
	AddComponent<RigidBodyComponent>(Text::GetHash("TopWall"), TopWallPosition, InWidth, InWallSize, 270.0f, 0.0f, false);

	Vec2f BottomWallPosition(InPosition.x, -(InHeight + InWallSize) / 2.0f);
	AddComponent<RigidBodyComponent>(Text::GetHash("BottomWall"), BottomWallPosition, InWidth, InWallSize, 90.0f, 0.0f, false);

	Vec2f LeftWallPosition(-(InWidth + InWallSize) / 2.0f, InPosition.y);
	AddComponent<RigidBodyComponent>(Text::GetHash("LeftWall"), LeftWallPosition, InWallSize, InHeight, 0.0f, 0.0f, false);

	Vec2f RightWallPosition(+(InWidth + InWallSize) / 2.0f, InPosition.y);
	AddComponent<RigidBodyComponent>(Text::GetHash("RightWall"), RightWallPosition, InWallSize, InHeight, 180.0f, 0.0f, false);

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