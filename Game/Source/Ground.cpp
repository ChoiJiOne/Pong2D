#include "Ground.h"
#include "Body.h"
#include "TextUtils.h"
#include "GroundGraphicsComponent.h"

Ground::Ground(World* InWorld, const Vec2f& InPosition, const float& InWidth, const float& InHeight)
	: GameObject(InWorld)
{
	Body_ = std::make_unique<Body>(InPosition, InWidth, InHeight, 0.0f, 0.0f);

	AddComponent<GroundGraphicsComponent>(TextUtils::GetHash("Graphics"));
}

Ground::~Ground()
{
}

void Ground::Update(Input& InInput, float InDeltaSeconds)
{
}

void Ground::Render(Graphics& InGraphics)
{
	GetComponent<GroundGraphicsComponent>(TextUtils::GetHash("Graphics"))->Tick(InGraphics);
}
