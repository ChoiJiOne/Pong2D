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
	BoundingBox_ = MathUtils::CalculateBoundingBox(Position_, Width_, Height_);
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
	BoundingBox_ = MathUtils::CalculateBoundingBox(Position_, Width_, Height_);
}

void RigidBodyComponent::SetPosition(const Vec2f& InPosition)
{
	Position_ = InPosition;
	BoundingBox_ = MathUtils::CalculateBoundingBox(Position_, Width_, Height_);
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

	BoundingBox_ = MathUtils::CalculateBoundingBox(Position_, Width_, Height_);
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
		break;

	default:
		ENFORCE_THROW_EXCEPTION("undefined rigid body type");
	}

	BoundingBox_ = MathUtils::CalculateBoundingBox(Position_, Width_, Height_);
}

RigidBodyComponent::ERelation RigidBodyComponent::GetRelation(const RigidBodyComponent& InRigidBody)
{
	if (Type_ == EType::NONE && InRigidBody.GetType() == EType::NONE)
	{

	}


	return ERelation();
}
