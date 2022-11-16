#include "PlayerGraphicsComponent.h"
#include "RigidBody.h"
#include "GameObject.h"
#include "Graphics.h"

void PlayerGraphicsComponent::Tick(Graphics& InGraphics)
{
	Vec2f Center = Object_->GetCenter();

	InGraphics.DrawFillRect2D(
		Vec2i(static_cast<int32_t>(Center.x), static_cast<int32_t>(Center.y)),
		static_cast<int32_t>(Object_->GetWidth()),
		static_cast<int32_t>(Object_->GetHeight()),
		ColorUtils::White
	);
}
