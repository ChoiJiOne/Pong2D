#include "RigidBody.h"
#include "MathUtils.h"
#include "Macro.h"

RigidBody::RigidBody(
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

RigidBody::RigidBody(RigidBody&& InInstance) noexcept
{
	Center_ = InInstance.Center_;
	bCanMove_ = InInstance.bCanMove_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
	BoundingPositions_ = InInstance.BoundingPositions_;
}

RigidBody::RigidBody(const RigidBody& InInstance) noexcept
{
	Center_ = InInstance.Center_;
	bCanMove_ = InInstance.bCanMove_;
	Width_ = InInstance.Width_;
	Height_ = InInstance.Height_;
	Rotate_ = InInstance.Rotate_;
	Velocity_ = InInstance.Velocity_;
	BoundingPositions_ = InInstance.BoundingPositions_;
}

RigidBody::~RigidBody()
{
}

RigidBody& RigidBody::operator=(RigidBody&& InInstance) noexcept
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

RigidBody& RigidBody::operator=(const RigidBody& InInstance) noexcept
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

void RigidBody::SetCenter(const Vec2f& InCenter)
{
	Center_ = InCenter;
	BoundingPositions_ = MathUtils::CalculateBoundingPositions(Center_, Width_, Height_);
}

void RigidBody::SetWidth(const float& InWidth)
{
	Width_ = InWidth;
	BoundingPositions_ = MathUtils::CalculateBoundingPositions(Center_, Width_, Height_);
}

void RigidBody::SetHeight(const float& InHeight)
{
	Height_ = InHeight;
	BoundingPositions_ = MathUtils::CalculateBoundingPositions(Center_, Width_, Height_);
}

bool RigidBody::IsCollision(const RigidBody& InRigidBody)
{
	Vec2f MinPosition = BoundingPositions_[0];
	Vec2f MaxPosition = BoundingPositions_[2];

	Vec2f OtherMinPosition = InRigidBody.BoundingPositions_[0];
	Vec2f OtherMaxPosition = InRigidBody.BoundingPositions_[2];

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

bool RigidBody::IsInclude(const RigidBody& InRigidBody)
{
	const std::array<Vec2f, 4>& BoundingPositions = InRigidBody.GetBoundingPositions();

	for (const auto& BoundingPosition : BoundingPositions)
	{
		if (!IsIncludePositionInBoundingPositions(BoundingPosition))
		{
			return false;
		}
	}

	return true;
}

bool RigidBody::IsIncludePositionInBoundingPositions(const Vec2f& InPosition)
{
	Vec2f MinPosition = BoundingPositions_[0];
	Vec2f MaxPosition = BoundingPositions_[2];

	return (MinPosition.x <= InPosition.x && InPosition.x <= MaxPosition.x)
		&& (MinPosition.y <= InPosition.y && InPosition.y <= MaxPosition.y);
}
