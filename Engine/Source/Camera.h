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
	 * 2D World 내의 카메라 위치를 얻습니다.
	 * 
	 * @return 2D World 내의 카메라 위치를 반환합니다.
	 */
	Vec2f GetPosition() const { return Position_; }


	/**
	 * 2D World 내의 카메라 위치를 설정합니다.
	 * 
	 * @param InPosition - 설정할 카메라 위치입니다.
	 */
	void SetPosition(const Vec2f& InPosition);


	/**
	 * 2D World 내의 카메라 가로 크기를 얻습니다.
	 * 
	 * @return 2D World 내의 카메라 가로 크기를 반환합니다.
	 */
	float GetWidth() const { return Width_; }


	/**
	 * 2D World 내의 카메라 가로 크기를 설정합니다.
	 * 
	 * @param InWidth - 설정할 카메라의 가로 크기입니다.
	 */
	void SetWidth(const float& InWidth);


	/**
	 * 2D World 내의 카메라 세로 크기를 얻습니다.
	 * 
	 * @return 2D World 내의 카메라 세로 크기를 반환합니다.
	 */
	float GetHeight() const { return Height_; }


	/**
	 * 2D World 내의 카메라 세로 크기를 설정합니다.
	 *
	 * @param InHeight - 설정할 카메라의 세로 크기입니다.
	 */
	void SetHeight(const float& InHeight);


	/**
	 * 2D World 내의 카메라 가로, 세로 크기를 얻습니다.
	 *
	 * @param OutWidth - 2D World 내의 카메라 가로 크기입니다.
	 * @param OutHeight - 2D World 내의 카메라 세로 크기입니다.
	 */
	void GetSize(float& OutWidth, float& OutHeight)
	{
		OutWidth = Width_;
		OutHeight = Height_;
	}


	 /**
	  * 2D World 내의 카메라 가로, 세로 크기를 설정합니다.
	  *
	  * @parma InWidth - 설정할 카메라의 가로 크기입니다.
	  * @param InHeight - 설정할 카메라의 세로 크기입니다.
	  */
	void SetSize(const float& InWidth, const float& InHeight);


	/**
	 * 2D World 내의 카메라 뱡향 각도를 얻습니다.
	 * 
	 * @return 2D World 내의 카메라 방향 각도를 반환합니다.
	 */
	float GetRotate() const { return Rotate_; }


	/**
	 * 2D World 내의 카메라 뱡향 각도를 설정합니다.
	 *
	 * @param InRotate - 설정할 카메라의 방향 각도입니다.
	 */
	void SetRotate(const float& InRotate) { Rotate_ = InRotate; }


	/**
	 * 2D World 내의 카메라의 속력을 얻습니다.
	 * 
	 * @return 2D World 내의 카메라의 속력을 반환합니다.
	 */
	float GetVelocity() const { return Velocity_; }


	/**
	 * 2D World 내의 카메라의 속력을 설정합니다.
	 * 
	 * @param InVelocity - 설정할 카메라의 속력입니다.
	 */
	void SetVelocity(const float& InVelocity) { Velocity_ = InVelocity; }


	/**
	 * 초단위 델타 시간값 만큼 카메라를 움직입니다.
	 *
	 * @param InDeltaSeconds - 카메라를 움직일 초단위 델타 시간 값입니다.
	 */
	void Move(float InDeltaSeconds);


	/**
	 * 입력 받은 월드 좌표를 카메라를 기준으로 윈도우 좌표로 변환합니다.
	 * 즉, 월드 좌표 => 카메라 좌표 => 윈도우 좌표 로 변환합니다.
	 * 
	 * @param InWorldPosition - 변환할 월드 좌표입니다.
	 * 
	 * @return 변환된 윈도우 좌표를 반환합니다.
	 */
	Vec2f ConvertToWindowPosition(const Vec2f& InWorldPosition);


private:
	/**
	 * 2D 월드 상의 카메라 현재 위치입니다.
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