#include "ScoreBoardRenderComponent.h"
#include "ScoreBoard.h"

#include <Text.hpp>
#include <ContentManager.h>
#include <RigidBodyComponent.h>
#include <GameObject.h>
#include <Renderer.h>
#include <Camera.h>

void ScoreBoardRenderComponent::Tick(Renderer& InRenderer, Camera& InCamera)
{
	ScoreBoard* ScoreBoardObject = reinterpret_cast<ScoreBoard*>(GetGameObject());
	RigidBodyComponent* RigidBody = ScoreBoardObject->GetComponent<RigidBodyComponent>(Text::GetHash("Body"));

	Vec2i Position = Math::ConvertPixelCoordinate(InCamera.ConvertToWindowPosition(RigidBody->GetPosition()));

	InRenderer.DrawText2D(
		ContentManager::Get().GetFont(Text::GetHash("Font128")),
		Text::Format(L"%d : %d", ScoreBoardObject->GetPlayer1Score(), ScoreBoardObject->GetPlayer2Score()),
		Position,
		Color_
	);
}
