#include "Player.h"

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

	float Rotate = Type_ == EType::PLAYER1 ? 0.0f : 180.0f;
	AddComponent<RigidBodyComponent>(Text::GetHash("body"), InPosition, InWidth, InHeight, Rotate, InVelocity, false);
}

Player::~Player()
{
}

void Player::Update(Input& InInput, float InDeltaSeconds)
{
}

void Player::Render(Renderer& InRenderer, Camera& InCamera)
{
}
