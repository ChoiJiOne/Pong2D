#include "Player.h"
#include "RigidBody.h"
#include "PlayerInputComponent.h"
#include "PlayerPhysicComponent.h"
#include "PlayerGraphicsComponent.h"
#include "TextUtils.h"

Player::Player(
	World* InWorld,
	const EType& InType,
	const Vec2f& InPosition,
	const float& InWidth,
	const float& InHeight,
	const float& InVelocity
) : GameObject(InWorld)
{
	Type_ = InType;

	SetCenter(InPosition);
	SetWidth(InWidth);
	SetHeight(InHeight);
	SetRotate(0.0f);
	SetVelocity(InVelocity);
	SetCanMove(false);

	AddComponent<PlayerInputComponent>(TextUtils::GetHash("Input"));
	AddComponent<PlayerPhysicComponent>(TextUtils::GetHash("Physic"));
	AddComponent<PlayerGraphicsComponent>(TextUtils::GetHash("Graphics"));
}

Player::~Player()
{
}

void Player::Update(Input& InInput, float InDeltaSeconds)
{
	GetComponent<PlayerInputComponent>(TextUtils::GetHash("Input"))->Tick(InInput);
	GetComponent<PlayerPhysicComponent>(TextUtils::GetHash("Physic"))->Tick(*World_, InDeltaSeconds);
}

void Player::Render(Graphics& InGraphics)
{
	GetComponent<PlayerGraphicsComponent>(TextUtils::GetHash("Graphics"))->Tick(InGraphics);
}
