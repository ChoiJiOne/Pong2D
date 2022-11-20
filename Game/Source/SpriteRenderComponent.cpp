#include "SpriteRenderComponent.h"

#include <RigidBodyComponent.h>
#include <ContentManager.h>
#include <Text.hpp>
#include <GameObject.h>
#include <Renderer.h>
#include <Camera.h>

void SpriteRenderComponent::Tick(Renderer& InRenderer, Camera& InCamera)
{
	RigidBodyComponent* RigidBody = GetGameObject()->GetComponent<RigidBodyComponent>(Text::GetHash("Body"));
	Texture& SpriteTexture = ContentManager::Get().GetTexture(SpriteKey_);

	InRenderer.DrawTexture2D(
		SpriteTexture,
		Math::ConvertPixelCoordinate(InCamera.ConvertToWindowPosition(RigidBody->GetPosition())),
		static_cast<int32_t>(RigidBody->GetWidth()),
		static_cast<int32_t>(RigidBody->GetHeight())
	);
}
