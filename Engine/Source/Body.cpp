#include "Body.h"
#include "MathUtils.h"
#include "Macro.h"

Body::Body(
	const Vec2f& InCenter,
	const float& InWidth,
	const float& InHeight,
	const float& InRotate,
	const float& InVelocity,
	bool bCanMove
)
{
	Center_ = InCenter;
	Width_ = InWidth;
	Height_ = InHeight;
	Rotate_ = InRotate;
	Velocity_ = InVelocity;
	bCanMove_ = bCanMove;

	BoundingPositions_ = MathUtils::CalculateBoundingPositions(Center_, Width_, Height_);
}

Body::Body(Body&& InInstance) noexcept
{
	Center_ = InInstance.Center_;
	bCanMove_ = InInstance.bCanMove_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
	BoundingPositions_ = InInstance.BoundingPositions_;
}

Body::Body(const Body& InInstance) noexcept
{
	Center_ = InInstance.Center_;
	bCanMove_ = InInstance.bCanMove_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
	BoundingPositions_ = InInstance.BoundingPositions_;
}

Body::~Body()
{
}

Body& Body::operator=(Body&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Center_ = InInstance.Center_;
	bCanMove_ = InInstance.bCanMove_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
	BoundingPositions_ = InInstance.BoundingPositions_;

	return *this;
}

Body& Body::operator=(const Body& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	Center_ = InInstance.Center_;
	bCanMove_ = InInstance.bCanMove_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
	BoundingPositions_ = InInstance.BoundingPositions_;

	return *this;
}

void Body::SetCenter(const Vec2f& InCenter)
{
	Center_ = InCenter;
	BoundingPositions_ = MathUtils::CalculateBoundingPositions(Center_, Width_, Height_);
}

void Body::SetWidth(const float& InWidth)
{
	Width_ = InWidth;
	BoundingPositions_ = MathUtils::CalculateBoundingPositions(Center_, Width_, Height_);
}

void Body::SetHeight(const float& InHeight)
{
	Height_ = InHeight;
	BoundingPositions_ = MathUtils::CalculateBoundingPositions(Center_, Width_, Height_);
}

bool Body::IsCollision(const Body& InBody)
{
	Vec2f MinPosition = BoundingPositions_[0];
	Vec2f MaxPosition = BoundingPositions_[2];

	Vec2f OtherMinPosition = InBody.BoundingPositions_[0];
	Vec2f OtherMaxPosition = InBody.BoundingPositions_[2];

	if (MinPosition.x > OtherMaxPosition.x || MaxPosition.x < OtherMinPosition.x)
	{
		return false;
	}

	if (MinPosition.y > OtherMaxPosition.y || MaxPosition.y < OtherMinPosition.y)
	{
		return false;
	}

	return true;
}