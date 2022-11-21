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
	Normals_.insert({ ENormal::TOP,    Vec2f(0.0f, -1.0f) });
	Normals_.insert({ ENormal::BOTTOM, Vec2f(0.0f, +1.0f) });
	Normals_.insert({ ENormal::LEFT,   Vec2f(+1.0f, 0.0f) });
	Normals_.insert({ ENormal::RIGHT,  Vec2f(-1.0f, 0.0f) });

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

Vec2f Ground::GetNormal(const ENormal& InType) const
{
	return Normals_.at(InType);
}
