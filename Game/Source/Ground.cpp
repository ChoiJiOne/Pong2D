#include "Ground.h"
#include "RigidBody.h"
#include "TextUtils.h"
#include "GroundGraphicsComponent.h"

Ground::Ground(World* InWorld, const Vec2f& InPosition, const float& InWidth, const float& InHeight)
	: GameObject(InWorld)
{
	SetCenter(InPosition);
	SetWidth(InWidth);
	SetHeight(InHeight);
	SetRotate(0.0f);
	SetVelocity(0.0f);
	SetCanMove(false);

	AddComponent<GroundGraphicsComponent>(TextUtils::GetHash("Graphics"));
}

Ground::~Ground()
{
}

void Ground::Update(Input& InInput, float InDeltaSeconds)
{
}

void Ground::Render(Graphics& InGraphics, Camera& InCamera)
{
	GetComponent<GroundGraphicsComponent>(TextUtils::GetHash("Graphics"))->Tick(InGraphics, InCamera);
}
