#pragma once

#include <Math.hpp>


/**
 * 2D ī�޶� Ŭ�����Դϴ�.
 */
class Camera
{
public:
	/**
	 * 2D World ���� ī�޶� �������Դϴ�.
	 *
	 * @param InPosition - 2D World ���� ī�޶� ��ġ�Դϴ�.
	 * @param InWidth - ī�޶��� ���� ũ���Դϴ�.
	 * @param InHeight - ī�޶��� ���� ũ���Դϴ�.
	 * @param InRotate - ī�޶��� �̵� �����Դϴ�.
	 * @param InVelocity - ī�޶��� �̵� �ӷ��Դϴ�.
	 */
	explicit Camera(
		const Vec2f& InPosition,
		const float& InWidth,
		const float& InHeight,
		const float& InRotate = 0.0f,
		const float& InVelocity = 0.0f
	);


	/**
	 * 2D World ���� ī�޶��� ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ī�޶� �ν��Ͻ��Դϴ�.
	 */
	Camera(Camera&& InInstance) noexcept;


	/**
	 * 2D World ���� ī�޶��� ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ī�޶� �ν��Ͻ��Դϴ�.
	 */
	Camera(const Camera& InInstance) noexcept;


	/**
	 * 2D World ���� ī�޶��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Camera() {}


	/**
	 * 2D World ���� ī�޶��� ���� �������Դϴ�..
	 *
	 * @param InInstance - ������ ī�޶� �ν��Ͻ��Դϴ�.
	 *
	 * @param ������ ī�޶��� �����ڸ� ��ȯ�մϴ�.
	 */
	Camera& operator=(Camera&& InInstance) noexcept;


	/**
	 * 2D World ���� ī�޶��� ���� �������Դϴ�..
	 *
	 * @param InInstance - ������ ī�޶� �ν��Ͻ��Դϴ�.
	 *
	 * @param ������ ī�޶��� �����ڸ� ��ȯ�մϴ�.
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
	 * ī�޶��� ���� ��ġ�Դϴ�.
	 */
	Vec2f Position_;


	/**
	 * ī�޶��� ���� ũ���Դϴ�.
	 */
	float Width_ = 0.0f;


	/**
	 * ī�޶��� ���� ũ���Դϴ�.
	 */
	float Height_ = 0.0f;


	/**
	 * ī�޶��� �̵� ���� ���Դϴ�.
	 */
	float Rotate_ = 0.0f;


	/**
	 * ī�޶��� �̵� �ӷ��Դϴ�.
	 */
	float Velocity_ = 0.0f;


	/**
	 * ī�޶��� ��� �����Դϴ�.
	 */
	BoundingBox BoundingBox_;
};