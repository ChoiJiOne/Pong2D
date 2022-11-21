#include "RigidBodyComponent.h"

RigidBodyComponent::RigidBodyComponent(
	GameObject* InObject, 
	const Vec2f& InPosition, 
	const float& InWidth, 
	const float& InHeight, 
	const float& InRotate, 
	const float& InVelocity, 
	bool bCanMove
) : Component(InObject)
{
	Type_ = EType::AABB;
	Position_ = InPosition;
	Width_ = InWidth;
	Height_ = InHeight;
	Rotate_ = InRotate;
	Velocity_ = InVelocity;
	bCanMove_ = bCanMove;
	BoundingBox_ = Math::CalculateBoundingBox(Position_, Width_, Height_);
}

void RigidBodyComponent::SetPosition(const Vec2f& InPosition)
{
	Position_ = InPosition;
	BoundingBox_ = Math::CalculateBoundingBox(Position_, Width_, Height_);
}

void RigidBodyComponent::SetWidth(const float& InWidth)
{
	Width_ = InWidth;
	BoundingBox_ = Math::CalculateBoundingBox(Position_, Width_, Height_);
}

void RigidBodyComponent::SetHeight(const float& InHeight)
{
	Height_ = InHeight;
	BoundingBox_ = Math::CalculateBoundingBox(Position_, Width_, Height_);
}

bool RigidBodyComponent::IsInner(RigidBodyComponent* InRigidBody)
{
	if (Type_ == EType::NONE || InRigidBody->Type_ == EType::NONE) return false;

	Vec2f MinPosition = BoundingBox_[0];
	Vec2f MaxPosition = BoundingBox_[2];

	Vec2f OtherMinPosition = InRigidBody->BoundingBox_[0];
	Vec2f OtherMaxPosition = InRigidBody->BoundingBox_[2];

	return (MinPosition.x < OtherMinPosition.x && OtherMaxPosition.x < MaxPosition.x)
		&& (MinPosition.y < OtherMinPosition.y && OtherMaxPosition.y < MaxPosition.y);
}

bool RigidBodyComponent::IsOutter(RigidBodyComponent* InRigidBody)
{
	if (Type_ == EType::NONE || InRigidBody->Type_ == EType::NONE) return false;

	Vec2f MinPosition = BoundingBox_[0];
	Vec2f MaxPosition = BoundingBox_[2];

	Vec2f OtherMinPosition = InRigidBody->BoundingBox_[0];
	Vec2f OtherMaxPosition = InRigidBody->BoundingBox_[2];

	return (MinPosition.x > OtherMaxPosition.x || MaxPosition.x < OtherMinPosition.x)
		&& (MinPosition.y > OtherMaxPosition.y || MaxPosition.y < OtherMinPosition.y);
}

bool RigidBodyComponent::IsCollision(RigidBodyComponent* InRigidBody)
{
	if (Type_ == EType::NONE || InRigidBody->Type_ == EType::NONE) return false;

	return !IsInner(InRigidBody) && !IsOutter(InRigidBody);
}
