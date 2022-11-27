#include "ScoreBoard.h"
#include "ScoreBoardRenderComponent.h"
#include "Player.h"

#include <World.h>
#include <Camera.h>
#include <Renderer.h>
#include <RigidBodyComponent.h>
#include <GameObject.h>
#include <Text.hpp>

ScoreBoard::ScoreBoard(
	World* InWorld,
	const std::size_t& InSignature,
	const Vec2f& InPosition,
	const float& InWidth,
	const float& InHeight,
	const LinearColor& InColor
): GameObject(InWorld, InSignature)
{
	AddComponent<RigidBodyComponent>(Text::GetHash("Body"), InPosition, InWidth, InHeight, 0.0f, 0.0f, false);
	AddComponent<ScoreBoardRenderComponent>(Text::GetHash("Render"), InColor);
}

ScoreBoard::~ScoreBoard()
{
}

void ScoreBoard::Update(Input& InInput, float InDeltaSeconds)
{
	Player* Player1 = reinterpret_cast<Player*>(World_->GetObject(Text::GetHash("Player1")));
	Player1Score_ = Player1->GetScore();

	Player* Player2 = reinterpret_cast<Player*>(World_->GetObject(Text::GetHash("Player2")));
	Player2Score_ = Player2->GetScore();
}

void ScoreBoard::Render(Renderer& InRenderer, Camera& InCamera)
{
	GetComponent<ScoreBoardRenderComponent>(Text::GetHash("Render"))->Tick(InRenderer, InCamera);
}
