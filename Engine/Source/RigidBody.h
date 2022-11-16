#pragma once

#include <array>

#include "Vector.h"


/**
 * 오브젝트의 바디입니다.
 * 이때, 오브젝트 바디는 AABB 기반으로 회전하지 않습니다.
 */
class RigidBody
{
public:
	/**
	 * 오브젝트 바디의 기본 생성자입니다.
	 * 이때, 디폴트 생성자에서 초기화를 수행하지 않으므로, 사용하기 전에 적절한 초기화를 수행해야 합니다.
	 */
	RigidBody() = default;


	/**
	 * 오브젝트의 바디의 생성자입니다.
	 * 
	 * @param InCenter - 오브젝트 바디의 중심 좌표입니다.
	 * @param InWidth - 오브젝트 바디의 가로 크기입니다.
	 * @param InHeight - 오브젝트 바디 세로 크기입니다.
	 * @param InRotate - 오브젝트 바디의 이동 방향 각도입니다.
	 * @param InVelocity - 오브젝트 바디의 속력입니다.
	 * @param bCanMove - 오브젝트 바디의 이동 여부입니다.
	 */
	explicit RigidBody(
		const Vec2f& InCenter, 
		const float& InWidth, 
		const float& InHeight,
		const float& InRotate = 0.0f,
		const float& InVelocity = 0.0f,
		bool bCanMove = false
	);
	
	
	/**
	 * 오브젝트 바디의 복사 생성자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 */
	RigidBody(RigidBody&& InInstance) noexcept;


	/**
	 * 오브젝트 바디의 복사 생성자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 */
	RigidBody(const RigidBody& InInstance) noexcept;


	/**
	 * 오브젝트 바디의 가상 소멸자입니다.
	 */
	virtual ~RigidBody();


	/**
	 * 오브젝트 바디의 대입 연산자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	RigidBody& operator=(RigidBody&& InInstance) noexcept;


	/**
	 * 오브젝트 바디의 대입 연산자입니다.
	 *
	 * @param InInstance - 복사할 객체입니다.
	 *
	 * @return 복사한 객체의 참조자를 반환합니다.
	 */
	RigidBody& operator=(const RigidBody& InInstance) noexcept;


	/**
	 * 오브젝트 바디의 중심 좌표를 얻습니다.
	 *
	 * @return 오브젝트 바디의 중심 좌표를 반환합니다.
	 */
	Vec2f GetCenter() const { return Center_; }


	/**
	 * 오브젝트 바디의 중심 좌표를 설정합니다.
	 *
	 * @param InCenter - 설정할 오브젝트 바디의 중심좌표입니다.
	 */
	void SetCenter(const Vec2f& InCenter);


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
	 * 오브젝트 바디의 경계 영역점을 얻습니다.
	 * 
	 * @return 오브젝트 바디의 경계 영역점을 반환합니다.
	 */
	const std::array<Vec2f, 4>& GetBoundingPositions() const { return BoundingPositions_; }


	/**
	 * 다른 오브젝트 바디와 충돌하는지 검사합니다.
	 * 
	 * @param InRigidBody - 검사를 수행할 다른 오브젝트의 몸체입니다.
	 * 
	 * @return 다른 오브젝트와 충돌한다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsCollision(const RigidBody& InRigidBody);


	/**
	 * 다른 오브젝트 바디를 포함하는지 검사합니다.
	 * 
	 * @param InRigidBody - 검사를 수행할 다른 오브젝트의 몸체입니다.
	 * 
	 * @return 다른 오브젝트를 포함한다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsInclude(const RigidBody& InRigidBody);


private:
	/**
	 * 점이 오브젝트의 경계 영역에 포함되는지 검사합니다.
	 * 
	 * @param InPosition - 검사를 수행할 점입니다.
	 * 
	 * @return 점을 포함한다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsIncludePositionInBoundingPositions(const Vec2f& InPosition);


private:
	/**
	 * 오브젝트 바디의 월드상 중심 좌표입니다.
	 */
	Vec2f Center_;


	/**
	 * 오브젝트 바디의 움직임 여부입니다.
	 */
	bool bCanMove_ = true;


	/**
	 * 오브젝트 바디의 가로 크기입니다.
	 */
	float Width_ = 0;


	/**
	 * 오브젝트 바디의 세로 크기입니다.
	 */
	float Height_ = 0;


	/**
	 * 오브젝트 바디의 월드상 이동 방향 각도입니다.
	 */
	float Rotate_ = 0.0f;


	/**
	 * 오브젝트 바디의 속력입니다.
	 */
	float Velocity_ = 0.0f;


	/**
	 * 오브젝트의 경계 영역점입니다.
	 */
	std::array<Vec2f, 4> BoundingPositions_;
};