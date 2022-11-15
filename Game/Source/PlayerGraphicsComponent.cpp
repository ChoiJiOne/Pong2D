#include "PlayerGraphicsComponent.h"
#include "Body.h"
#include "GameObject.h"
#include "Graphics.h"

void PlayerGraphicsComponent::Tick(Graphics& InGraphics)
{
	Body& ObjectBody = Object_->GetBody();
	Vec2f Center = ObjectBody.GetCenter();

	InGraphics.DrawFillRect2D(
		Vec2i(static_cast<int32_t>(Center.x), static_cast<int32_t>(Center.y)),
		static_cast<int32_t>(ObjectBody.GetWidth()),
		static_cast<int32_t>(ObjectBody.GetHeight()),
		ColorUtils::White
	);
}
