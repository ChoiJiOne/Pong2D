#include "Player.h"
#include "SpriteRenderComponent.h"
#include "PlayerInputComponent.h"
#include "PlayerPhysicComponent.h"

#include <Text.hpp>
#include <RigidBodyComponent.h>

Player::Player(
	World* InWorld, 
	const std::size_t& InSignature,
	const EType& InType, 
	const Vec2f& InPosition, 
	const float& InWidth, 
	const float& InHeight, 
	const float& InVelocity
) : GameObject(InWorld, InSignature)
{
	Type_ = InType;

	float Rotate = (Type_ == EType::PLAYER1) ? 0.0f : 180.0f;
	AddComponent<RigidBodyComponent>(Text::GetHash("Body"), InPosition, InWidth, InHeight, Rotate, InVelocity, false);

	std::size_t SpriteKey = (Type_ == EType::PLAYER1) ? Text::GetHash("PaddleRed") : Text::GetHash("PaddleBlue");
	AddComponent<SpriteRenderComponent>(Text::GetHash("Render"), SpriteKey);

	AddComponent<PlayerInputComponent>(Text::GetHash("Input"));
	AddComponent<PlayerPhysicComponent>(Text::GetHash("Physic"));
}

Player::~Player()
{
}

void Player::Update(Input& InInput, float InDeltaSeconds)
{
	GetComponent<PlayerInputComponent>(Text::GetHash("Input"))->Tick(InInput);
	GetComponent<PlayerPhysicComponent>(Text::GetHash("Physic"))->Tick(*World_, InDeltaSeconds);
}

void Player::Render(Renderer& InRenderer, Camera& InCamera)
{
	GetComponent<SpriteRenderComponent>(Text::GetHash("Render"))->Tick(InRenderer, InCamera);
}
