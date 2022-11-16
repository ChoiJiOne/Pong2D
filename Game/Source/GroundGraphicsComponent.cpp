#include "GroundGraphicsComponent.h"
#include "Camera.h"
#include "RigidBody.h"
#include "GameObject.h"
#include "MathUtils.h"
#include "Graphics.h"

void GroundGraphicsComponent::Tick(Graphics& InGraphics, Camera& InCamera)
{
	Vec2f Center = Object_->GetCenter();
	Vec2f CameraPosition = InCamera.GetPosition();
	int32_t Side = 50;

	Vec2f ConvertPosition;
	ConvertPosition.x = Center.x - CameraPosition.x + InCamera.GetWidth() / 2.0f;
	ConvertPosition.y = -Center.y + CameraPosition.y + InCamera.GetHeight() / 2.0f;

	InGraphics.DrawFillRect2D(
		MathUtils::ConvertPixelCoordinate(ConvertPosition),
		static_cast<int32_t>(Object_->GetWidth()) + Side,
		static_cast<int32_t>(Object_->GetHeight()) + Side,
		ColorUtils::White
	);

	InGraphics.DrawFillRect2D(
		MathUtils::ConvertPixelCoordinate(ConvertPosition),
		static_cast<int32_t>(Object_->GetWidth()),
		static_cast<int32_t>(Object_->GetHeight()),
		ColorUtils::Black
	);
}
