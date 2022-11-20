#pragma once

#include <Math.hpp>


/**
 * 2D 카메라 클래스입니다.
 */
class Camera
{
public:
	/**
	 * 2D World 내의 카메라 생성자입니다.
	 *
	 * @param InPosition - 2D World 내의 카메라 위치입니다.
	 * @param InWidth - 카메라의 가로 크기입니다.
	 * @param InHeight - 카메라의 세로 크기입니다.
	 * @param InRotate - 카메라의 이동 방향입니다.
	 * @param InVelocity - 카메라의 이동 속력입니다.
	 */
	explicit Camera(
		const Vec2f& InPosition,
		const float& InWidth,
		const float& InHeight,
		const float& InRotate = 0.0f,
		const float& InVelocity = 0.0f
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
	 * 2D World 내의 카메라의 가상 소멸자입니다.
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
	 * 
	 */
	Vec2f GetPosition() const { return Position_; }


	/**
	 * 
	 */
	void SetPosition(const Vec2f& InPosition);


	/**
	 * 
	 */
	float GetWidth() const { return Width_; }


	/**
	 * 
	 */
	void SetWidth(const float& InWidth);


	/**
	 * 
	 */
	float GetHeight() const { return Height_; }


	/**
	 * 
	 */
	void SetHeight(const float& InHeight);


	/**
	 * 
	 */
	float GetRotate() const { return Rotate_; }



	/**
	 * 
	 */
	void SetRotate(const float& InRotate) { Rotate_ = InRotate; }


	/**
	 * 
	 */
	float GetVelocity() const { return Velocity_; }


	/**
	 * 
	 */
	void SetVelocity(const float& InVelocity) { Velocity_ = InVelocity; }


	/**
	 * 
	 */
	Vec2f GetWindowPosition(const Vec2f& InWorldPosition);


private:
	/**
	 * 카메라의 현재 위치입니다.
	 */
	Vec2f Position_;


	/**
	 * 카메라의 가로 크기입니다.
	 */
	float Width_ = 0.0f;


	/**
	 * 카메라의 세로 크기입니다.
	 */
	float Height_ = 0.0f;


	/**
	 * 카메라의 이동 방향 각입니다.
	 */
	float Rotate_ = 0.0f;


	/**
	 * 카메라의 이동 속력입니다.
	 */
	float Velocity_ = 0.0f;


	/**
	 * 카메라의 경계 영역입니다.
	 */
	BoundingBox BoundingBox_;
};