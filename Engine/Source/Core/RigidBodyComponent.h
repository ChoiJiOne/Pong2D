#pragma once

#include "Core/Component.h"

#include "Misc/MathUtils.h"
#include "Misc/Vector.h"


/**
 * 게임 오브젝트의 리지드 바디 컴포넌트입니다.
 */
class RigidBodyComponent : public Component
{
public:
	/**
	 * 게임 오브젝트의 바디 타입입니다.
	 */
	enum class EType : int32_t
	{
		NONE   = 0,
		AABB   = 1,
		CIRCLE = 2
	};


	/**
	 * 다른 오브젝트의 바디와의 관계입니다.
	 */
	enum class ERelation : int32_t
	{
		NONE      = 0,
		OUTER     = 1,
		COLLISION = 2,
		INNER     = 3,
	};


public:
	/**
	 * 게임 오브젝트의 리지드 바디 컴포넌트의 생성자입니다.
	 * 이때, 이 생성자를 호출하면 바디의 타입은 AABB로 설정됩니다.
	 * 
	 * @param InObject - 이 컴포넌트를 소유한 게임 오브젝트입니다.
	 * @param InPosition - 오브젝트 바디의 중심 좌표입니다.
	 * @param InWidth - 오브젝트 바디의 가로 크기입니다.
	 * @param InHeight - 오브젝트 바디 세로 크기입니다.
	 * @param InRotate - 오브젝트 바디의 이동 방향 각도입니다.
	 * @param InVelocity - 오브젝트 바디의 속력입니다.
	 * @param bCanMove - 오브젝트 바디의 이동 여부입니다.
	 */
	explicit RigidBodyComponent(
		GameObject* InObject,
		const Vec2f& InPosition,
		const float& InWidth,
		const float& InHeight,
		const float& InRotate = 0.0f,
		const float& InVelocity = 0.0f,
		bool bCanMove = false
	);


	/**
	 * 게임 오브젝트의 리지드 바디 컴포넌트의 생성자입니다.
	 * 이때, 이 생성자를 호출하면 바디의 타입은 CIRCLE로 설정됩니다.
	 *
	 * @param InObject - 이 컴포넌트를 소유한 게임 오브젝트입니다.
	 * @param InPosition - 오브젝트 바디의 중심 좌표입니다.
	 * @param InWidth - 오브젝트 바디의 가로 크기입니다.
	 * @param InHeight - 오브젝트 바디 세로 크기입니다.
	 * @param InRotate - 오브젝트 바디의 이동 방향 각도입니다.
	 * @param InVelocity - 오브젝트 바디의 속력입니다.
	 * @param bCanMove - 오브젝트 바디의 이동 여부입니다.
	 */
	explicit RigidBodyComponent(
		GameObject* InObject,
		const Vec2f& InPosition,
		const float& InRadius,
		const float& InRotate = 0.0f,
		const float& InVelocity = 0.0f,
		bool bCanMove = false
	);


	/**
	 * 게임 오브젝트의 리지드 바디 컴포넌트 가상 소멸자입니다.
	 */
	virtual ~RigidBodyComponent() {}


	/**
	 * 게임 오브젝트 컴포넌트의 복사 생성자 및 대입 연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(RigidBodyComponent);


	/**
	 * 오브젝트 바디의 타입을 얻습니다.
	 * 
	 * @return 오브젝트 바디의 타입을 반환합니다.
	 */
	EType GetType() const { return Type_; }


	/**
	 * 오브젝트 바디의 중심 좌표를 얻습니다.
	 *
	 * @return 오브젝트 바디의 중심 좌표를 반환합니다.
	 */
	Vec2f GetPosition() const { return Position_; }


	/**
	 * 오브젝트 바디의 중심 좌표를 설정합니다.
	 *
	 * @param InCenter - 설정할 오브젝트 바디의 중심좌표입니다.
	 */
	void SetPosition(const Vec2f& InPosition);


	/**
	 * 오브젝트 바디의 움직임 여부를 얻습니다.
	 *
	 * @return 오브젝트 바디의 움직임 여부를 반환합니다.
	 */
	bool CanMove() const { return bCanMove_; }


	/**
	 * 오브젝트 바디의 움직임 여부를 설정합니다.
	 *
	 * @param 설정할 오브젝트 바디의 움직임 여부입니다.
	 */
	void SetCanMove(bool bCanMove) { bCanMove_ = bCanMove; }


	/**
	 * 오브젝트 바디의 가로 크기를 얻습니다.
	 *
	 * @return 오브젝트 바디의 가로 크기를 반환합니다.
	 */
	float GetWidth() const { return Width_; }


	/**
	 * 오브젝트 바디의 가로 크기를 설정합니다.
	 *
	 * @param InWidth - 설정할 오브젝트 바디의 가로 크기입니다.
	 */
	void SetWidth(const float& InWidth);


	/**
	 * 오브젝트 바디의 가로 세로 크기를 얻습니다.
	 *
	 * @return 오브젝트 바디의 세로 크기를 반환합니다.
	 */
	float GetHeight() const { return Height_; }


	/**
	 * 오브젝트 바디의 세로 크기를 설정합니다.
	 *
	 * @param InHeight - 설정할 오브젝트 바디의 세로 크기입니다.
	 */
	void SetHeight(const float& InHeight);


	/**
	 * 오브젝트 바디의 회전 각을 얻습니다.
	 * 이때, 각도는 육십분법 각도입니다.
	 *
	 * @return 오브젝트 바디의 회전 각을 반환합니다.
	 */
	float GetRotate() const { return Rotate_; }


	/**
	 * 오브젝트 바디의 이동 방향 각을 설정합니다.
	 * 이때, 각도는 육십분법 각도입니다.
	 *
	 * @param InRotate - 설정할 오브젝트 바디의 이동 방향 각을 방향입니다.
	 */
	void SetRotate(const float& InRotate) { Rotate_ = InRotate; }


	/**
	 * 오브젝트 바디의 속력를 얻습니다.
	 *
	 * @return 오브젝트의 속력를 반환합니다.
	 */
	float GetVelocity() const { return Velocity_; }


	/**
	 * 오브젝트 바디의 속력을 설정합니다.
	 *
	 * @param InVelocity - 설정할 오브젝트 바디의 속도입니다.
	 */
	void SetVelocity(const float& InVelocity) { Velocity_ = InVelocity; }


	/**
	 * 오브젝트 바디의 경계 영역을 얻습니다.
	 *
	 * @return 오브젝트 바디의 경계 영역을 반환합니다.
	 */
	const BoundingBox& GetBoundingBox() const { return BoundingBox_; }


	/**
	 * 다른 오브젝트 바디와의 관계를 얻습니다.
	 * 
	 * @param 관계를 확인할 다른 오브젝트의 바디입니다.
	 * 
	 * @return 다른 오브젝트와의 관계(ERelation)를 반환합니다.
	 */
	ERelation GetRelation(const RigidBodyComponent& InRigidBody);


private:
	/**
	 * 게임 오브젝트의 형태 타입입니다.
	 */
	EType Type_ = EType::NONE;


	/**
	 * 게임 오브젝트의 움직임 여부입니다.
	 */
	bool bCanMove_ = true;


	/**
	 * 게임 오브젝트의 월드 상 중심 좌표입니다.
	 */
	Vec2f Position_;


	/**
	 * 게임 오브젝트의 가로 크기입니다.
	 * 이때, 형태 타입이 CIRCLE이라면 Width와 Height 크기가 동일합니다.
	 */
	float Width_ = 0.0f;


	/**
	 * 게임 오브젝트의 세로 크기입니다.
	 * 이때, 형태 타입이 CIRCLE이라면 Width와 Height 크기가 동일합니다.
	 */
	float Height_ = 0.0f;


	/**
	 * 게임 오브젝트의 월드상 이동 방향 각도입니다.
	 */
	float Rotate_ = 0.0f;


	/**
	 * 게임 오브젝트의 속력입니다.
	 */
	float Velocity_ = 0.0f;


	/**
	 * 게임 오브젝트의 경계 상자입니다.
	 */
	BoundingBox BoundingBox_;
};