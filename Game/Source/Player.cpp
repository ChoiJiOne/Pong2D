#include "Player.h"
#include "Body.h"
#include "PlayerInputComponent.h"
#include "PlayerPhysicComponent.h"
#include "PlayerGraphicsComponent.h"
#include "TextUtils.h"

Player::Player(World* InWorld)
	: GameObject(InWorld)
{
	Body_ = std::make_unique<Body>(Vec2f(500.0f, 400.0f), 50.0f, 200.0f, 0.0f, 200.0f);

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
