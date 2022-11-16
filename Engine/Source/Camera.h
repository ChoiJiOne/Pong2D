#pragma once

#include "RigidBody.h"
#include "Vector.h"


/**
 * 2D World 내의 카메라입니다.
 */
class Camera : public RigidBody
{
public:
	/**
	 * 2D World 내 카메라의 디폴트 생성자입니다.
	 * 이때, 디폴트 생성자에서는 초기화를 수행하지 않으므로, 사용하기 전에 적절한 초기화를 수행해야 합니다.
	 */
	Camera() = default;


	/**
	 * 2D World 내의 카메라 생성자입니다.
	 * 이 생성자를 호출하면 카메라는 2D World의 원점에 배치됩니다.
	 * 
	 * @param InPosition - 2D World 내의 카메라 위치입니다.
	 * @param InWidth - 카메라의 가로 크기입니다.
	 * @param InHeight - 카메라의 세로 크기입니다.
	 * @param InRotate - 카메라의 이동 방향입니다.
	 * @param InVelocity - 카메라의 이동 속력입니다.
	 * @param bCanMove - 카메라의 이동 여부입니다.
	 */
	explicit Camera(
		const Vec2f& InPosition,
		const float& InWidth,
		const float& InHeight,
		const float& InRotate = 0.0f,
		const float& InVelocity = 0.0f,
		bool bCanMove = false
	);


	/**
	 * 2D World 내의 카메라의 복사 생성자입니다.
	 * 
	 * @param InInstance - 복사할 카메라 인스턴스입니다.
	 */
	Camera(Camera&& InInstance) noexcept;


	/**
	 * 2D World 내의 카메라의 복사 생성자입니다.
	 * 
	 * @param InInstance - 복사할 카메라 인스턴스입니다.
	 */
	Camera(const Camera& InInstance) noexcept;


	/**
	 * World 내의 2D 카메라 가상 소멸자입니다.
	 */
	virtual ~Camera() {}


	/**
	 * 2D World 내의 카메라의 대입 연산자입니다..
	 *
	 * @param InInstance - 복사할 카메라 인스턴스입니다.
	 * 
	 * @param 대입한 카메라의 참조자를 반환합니다.
	 */
	Camera& operator=(Camera&& InInstance) noexcept;


	/**
	 * 2D World 내의 카메라의 대입 연산자입니다..
	 *
	 * @param InInstance - 복사할 카메라 인스턴스입니다.
	 *
	 * @param 대입한 카메라의 참조자를 반환합니다.
	 */
	Camera& operator=(const Camera& InInstance) noexcept;


	/**
	 * 2D World 내의 카메라 위치를 얻습니다.
	 * 
	 * @return 2D World 내의 카메라 위치를 반환합니다.
	 */
	Vec2f GetPosition() const { return RigidBody::GetCenter(); }


	/**
	 * 2D World 내의 카메라의 위치를 설정합니다.
	 * 
	 * @param InPosition - 설정할 2D World 내의 카메라 위치입니다.
	 */
	void SetPosition(const Vec2f& InPosition) { RigidBody::SetCenter(InPosition); }


	/**
	 * 초단위 델타 시간값 만큼 카메라를 움직입니다.
	 * 
	 * @param InDeltaSeconds - 카메라를 움직일 초단위 델타 시간 값입니다.
	 */
	void Move(float InDeltaSeconds);
};