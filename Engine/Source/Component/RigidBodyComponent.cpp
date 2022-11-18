#include "RigidBodyComponent.h"
#include "Misc/MathUtils.h"
#include "Misc/MacroUtils.h"

RigidBodyComponent::~RigidBodyComponent()
{
}

void RigidBodyComponent::SetCenter(const Vec2f& InCenter)
{
	Center_ = InCenter;
	BoundingPositions_ = MathUtils::CalculateBoundingPositions(Center_, Width_, Height_);
}

void RigidBodyComponent::SetWidth(const float& InWidth)
{
	Width_ = InWidth;
	BoundingPositions_ = MathUtils::CalculateBoundingPositions(Center_, Width_, Height_);
}

void RigidBodyComponent::SetHeight(const float& InHeight)
{
	Height_ = InHeight;
	BoundingPositions_ = MathUtils::CalculateBoundingPositions(Center_, Width_, Height_);
}

bool RigidBodyComponent::IsCollision(const RigidBodyComponent& InRigidBody)
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

bool RigidBodyComponent::IsInclude(const RigidBodyComponent& InRigidBody)
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

bool RigidBodyComponent::IsIncludePositionInBoundingPositions(const Vec2f& InPosition)
{
	Vec2f MinPosition = BoundingPositions_[0];
	Vec2f MaxPosition = BoundingPositions_[2];

	return (MinPosition.x <= InPosition.x && InPosition.x <= MaxPosition.x)
		&& (MinPosition.y <= InPosition.y && InPosition.y <= MaxPosition.y);
}
