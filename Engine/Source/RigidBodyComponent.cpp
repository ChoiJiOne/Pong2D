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

RigidBodyComponent::RigidBodyComponent(
	GameObject* InObject, 
	const Vec2f& InPosition, 
	const float& InRadius, 
	const float& InRotate, 
	const float& InVelocity, 
	bool bCanMove
) : Component(InObject)
{
	Type_ = EType::CIRCLE;
	Position_ = InPosition;
	Width_ = InRadius;
	Height_ = InRadius;
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
	switch (Type_)
	{
	case EType::AABB:
		Width_ = InWidth;
		break;

	case EType::CIRCLE:
		Width_ = InWidth;
		Height_ = InWidth;
		break;

	case EType::NONE:
		break;

	default:
		ENFORCE_THROW_EXCEPTION("undefined rigid body type");
	}

	BoundingBox_ = Math::CalculateBoundingBox(Position_, Width_, Height_);
}

void RigidBodyComponent::SetHeight(const float& InHeight)
{
	switch (Type_)
	{
	case EType::AABB:
		Height_ = InHeight;
		break;

	case EType::CIRCLE:
		Width_ = InHeight;
		Height_ = InHeight;
		break;

	case EType::NONE:
		Width_ = 0.0f;
		Height_ = 0.0f;
		break;

	default:
		ENFORCE_THROW_EXCEPTION("undefined rigid body type");
	}

	BoundingBox_ = Math::CalculateBoundingBox(Position_, Width_, Height_);
}

bool RigidBodyComponent::IsInner(RigidBodyComponent* InRigidBody)
{
	if (Type_ == EType::NONE || InRigidBody->Type_ == EType::NONE) return false;

	bool bIsInner = false;

	if (Type_ == EType::AABB)
	{
		if (InRigidBody->Type_ == EType::AABB)
		{
			Vec2f MinPosition = BoundingBox_[0];
			Vec2f MaxPosition = BoundingBox_[2];

			Vec2f OtherMinPosition = InRigidBody->BoundingBox_[0];
			Vec2f OtherMaxPosition = InRigidBody->BoundingBox_[2];

			bIsInner = (MinPosition.x < OtherMinPosition.x && OtherMaxPosition.x < MaxPosition.x)
				&& (MinPosition.y < OtherMinPosition.y && OtherMaxPosition.y < MaxPosition.y);
		}
		else // InRigidBody->Type_ == EType::CIRCLE
		{





		}
	}
	else // Type_ == EType::CIRCLE
	{
		if (InRigidBody->Type_ == EType::AABB)
		{



		}
		else // InRigidBody->Type_ == EType::CIRCLE
		{



		}
	}

	return bIsInner;
}

bool RigidBodyComponent::IsOutter(RigidBodyComponent* InRigidBody)
{
	if (Type_ == EType::NONE || InRigidBody->Type_ == EType::NONE) return false;

	bool bIsOutter = false;

	if (Type_ == EType::AABB)
	{
		if (InRigidBody->Type_ == EType::AABB)
		{
			Vec2f MinPosition = BoundingBox_[0];
			Vec2f MaxPosition = BoundingBox_[2];

			Vec2f OtherMinPosition = InRigidBody->BoundingBox_[0];
			Vec2f OtherMaxPosition = InRigidBody->BoundingBox_[2];

			bIsOutter = (MinPosition.x > OtherMaxPosition.x || MaxPosition.x < OtherMinPosition.x)
				&& (MinPosition.y > OtherMaxPosition.y || MaxPosition.y < OtherMinPosition.y);
		}
		else // InRigidBody->Type_ == EType::CIRCLE
		{





		}
	}
	else // Type_ == EType::CIRCLE
	{
		if (InRigidBody->Type_ == EType::AABB)
		{



		}
		else // InRigidBody->Type_ == EType::CIRCLE
		{



		}
	}

	return false;
}

bool RigidBodyComponent::IsCollision(RigidBodyComponent* InRigidBody)
{
	if (Type_ == EType::NONE || InRigidBody->Type_ == EType::NONE) return false;

	return !IsInner(InRigidBody) && !IsOutter(InRigidBody);
}
