#include "GroundRenderComponent.h"

#include <RigidBodyComponent.h>
#include <Text.hpp>
#include <GameObject.h>
#include <Renderer.h>
#include <Camera.h>

void GroundRenderComponent::Tick(Renderer& InRenderer, Camera& InCamera)
{
	RigidBodyComponent* RigidBody = GetGameObject()->GetComponent<RigidBodyComponent>(Text::GetHash("Body"));
	
	InRenderer.DrawRect2D(
		Math::ConvertPixelCoordinate(InCamera.ConvertToWindowPosition(RigidBody->GetPosition())),
		static_cast<int32_t>(RigidBody->GetWidth()),
		static_cast<int32_t>(RigidBody->GetHeight()),
		Color_
	);
}