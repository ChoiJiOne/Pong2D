#include <Camera.h>

Camera::Camera(const Vec2f& InPosition, const float& InWidth, const float& InHeight, const float& InRotate, const float& InVelocity)
{
	Position_ = InPosition;
	Width_ = InWidth;
	Height_ = InHeight;
	Rotate_ = InRotate;
	Velocity_ = InVelocity;
	BoundingBox_ = Math::CalculateBoundingBox(Position_, Width_, Height_);
}

Camera::Camera(Camera&& InInstance) noexcept
{
	Position_ = InInstance.Position_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
	BoundingBox_ = InInstance.BoundingBox_;
}

Camera::Camera(const Camera& InInstance) noexcept
{
	Position_ = InInstance.Position_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
	BoundingBox_ = InInstance.BoundingBox_;
}

Camera& Camera::operator=(Camera&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Position_ = InInstance.Position_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
	BoundingBox_ = InInstance.BoundingBox_;

	return *this;
}

Camera& Camera::operator=(const Camera& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Position_ = InInstance.Position_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
	BoundingBox_ = InInstance.BoundingBox_;

	return *this;
}

void Camera::SetPosition(const Vec2f& InPosition)
{
	Position_ = InPosition;
	BoundingBox_ = Math::CalculateBoundingBox(Position_, Width_, Height_);
}

void Camera::SetWidth(const float& InWidth)
{
	Width_ = InWidth;
	BoundingBox_ = Math::CalculateBoundingBox(Position_, Width_, Height_);
}

void Camera::SetHeight(const float& InHeight)
{
	Height_ = InHeight;
	BoundingBox_ = Math::CalculateBoundingBox(Position_, Width_, Height_);
}

void Camera::Move(float InDeltaSeconds)
{
	float CosTheta = cosf(Math::ToRadian(Rotate_));
	float SinTheta = sinf(Math::ToRadian(Rotate_));

	Position_.x += (CosTheta * GetVelocity() * InDeltaSeconds);
	Position_.y += (SinTheta * GetVelocity() * InDeltaSeconds);
}

Vec2f Camera::ConvertToWindowPosition(const Vec2f& InWorldPosition)
{
	return Vec2f(
		 InWorldPosition.x - Position_.x + Width_  / 2.0f,
		-InWorldPosition.y + Position_.y + Height_ / 2.0f
	);
}
