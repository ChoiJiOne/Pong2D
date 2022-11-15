#include "GroundGraphicsComponent.h"
#include "Body.h"
#include "GameObject.h"
#include "Graphics.h"

void GroundGraphicsComponent::Tick(Graphics& InGraphics)
{
	Body& ObjectBody = Object_->GetBody();
	Vec2f Center = ObjectBody.GetCenter();
	int32_t Side = 50;

	InGraphics.DrawFillRect2D(
		Vec2i(static_cast<int32_t>(Center.x), static_cast<int32_t>(Center.y)),
		static_cast<int32_t>(ObjectBody.GetWidth()) + Side,
		static_cast<int32_t>(ObjectBody.GetHeight()) + Side,
		ColorUtils::White
	);

	InGraphics.DrawFillRect2D(
		Vec2i(static_cast<int32_t>(Center.x), static_cast<int32_t>(Center.y)),
		static_cast<int32_t>(ObjectBody.GetWidth()),
		static_cast<int32_t>(ObjectBody.GetHeight()),
		ColorUtils::Black
	);
}
