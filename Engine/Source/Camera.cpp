#include "Camera.h"
#include "MathUtils.h"

Camera::Camera(
	const Vec2f& InPosition, 
	const float& InWidth, 
	const float& InHeight, 
	const float& InRotate, 
	const float& InVelocity,
	bool bCanMove
) : RigidBody(InPosition, InWidth, InHeight, InRotate, InVelocity, bCanMove)
{
}

Camera::Camera(Camera&& InInstance) noexcept : RigidBody(InInstance) {}

Camera::Camera(const Camera& InInstance) noexcept : RigidBody(InInstance) {}

Camera& Camera::operator=(Camera&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	RigidBody::operator=(InInstance);

	return *this;
}

Camera& Camera::operator=(const Camera& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	RigidBody::operator=(InInstance);

	return *this;
}

void Camera::Move(float InDeltaSeconds)
{
	float Rotate = GetRotate();
	float CosTheta = static_cast<float>(cos(MathUtils::ToRadian(Rotate)));
	float SinTheta = static_cast<float>(sin(MathUtils::ToRadian(Rotate)));

	Vec2f Position = GetPosition();
	Position.x += (CosTheta * GetVelocity() * InDeltaSeconds);
	Position.y += (SinTheta * GetVelocity() * InDeltaSeconds);

	SetPosition(Position);
}
