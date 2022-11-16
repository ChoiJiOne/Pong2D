#include "GroundGraphicsComponent.h"
#include "RigidBody.h"
#include "GameObject.h"
#include "Graphics.h"

void GroundGraphicsComponent::Tick(Graphics& InGraphics)
{
	Vec2f Center = Object_->GetCenter();
	int32_t Side = 50;

	InGraphics.DrawFillRect2D(
		Vec2i(static_cast<int32_t>(Center.x), static_cast<int32_t>(Center.y)),
		static_cast<int32_t>(Object_->GetWidth()) + Side,
		static_cast<int32_t>(Object_->GetHeight()) + Side,
		ColorUtils::White
	);

	InGraphics.DrawFillRect2D(
		Vec2i(static_cast<int32_t>(Center.x), static_cast<int32_t>(Center.y)),
		static_cast<int32_t>(Object_->GetWidth()),
		static_cast<int32_t>(Object_->GetHeight()),
		ColorUtils::Black
	);
}
