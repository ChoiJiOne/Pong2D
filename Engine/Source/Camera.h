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
	 * 2D World ���� ī�޶� ��ġ�� ����ϴ�.
	 * 
	 * @return 2D World ���� ī�޶� ��ġ�� ��ȯ�մϴ�.
	 */
	Vec2f GetPosition() const { return Position_; }


	/**
	 * 2D World ���� ī�޶� ��ġ�� �����մϴ�.
	 * 
	 * @param InPosition - ������ ī�޶� ��ġ�Դϴ�.
	 */
	void SetPosition(const Vec2f& InPosition);


	/**
	 * 2D World ���� ī�޶� ���� ũ�⸦ ����ϴ�.
	 * 
	 * @return 2D World ���� ī�޶� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetWidth() const { return Width_; }


	/**
	 * 2D World ���� ī�޶� ���� ũ�⸦ �����մϴ�.
	 * 
	 * @param InWidth - ������ ī�޶��� ���� ũ���Դϴ�.
	 */
	void SetWidth(const float& InWidth);


	/**
	 * 2D World ���� ī�޶� ���� ũ�⸦ ����ϴ�.
	 * 
	 * @return 2D World ���� ī�޶� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetHeight() const { return Height_; }


	/**
	 * 2D World ���� ī�޶� ���� ũ�⸦ �����մϴ�.
	 *
	 * @param InHeight - ������ ī�޶��� ���� ũ���Դϴ�.
	 */
	void SetHeight(const float& InHeight);


	/**
	 * 2D World ���� ī�޶� ����, ���� ũ�⸦ ����ϴ�.
	 *
	 * @param OutWidth - 2D World ���� ī�޶� ���� ũ���Դϴ�.
	 * @param OutHeight - 2D World ���� ī�޶� ���� ũ���Դϴ�.
	 */
	void GetSize(float& OutWidth, float& OutHeight)
	{
		OutWidth = Width_;
		OutHeight = Height_;
	}


	 /**
	  * 2D World ���� ī�޶� ����, ���� ũ�⸦ �����մϴ�.
	  *
	  * @parma InWidth - ������ ī�޶��� ���� ũ���Դϴ�.
	  * @param InHeight - ������ ī�޶��� ���� ũ���Դϴ�.
	  */
	void SetSize(const float& InWidth, const float& InHeight);


	/**
	 * 2D World ���� ī�޶� ���� ������ ����ϴ�.
	 * 
	 * @return 2D World ���� ī�޶� ���� ������ ��ȯ�մϴ�.
	 */
	float GetRotate() const { return Rotate_; }


	/**
	 * 2D World ���� ī�޶� ���� ������ �����մϴ�.
	 *
	 * @param InRotate - ������ ī�޶��� ���� �����Դϴ�.
	 */
	void SetRotate(const float& InRotate) { Rotate_ = InRotate; }


	/**
	 * 2D World ���� ī�޶��� �ӷ��� ����ϴ�.
	 * 
	 * @return 2D World ���� ī�޶��� �ӷ��� ��ȯ�մϴ�.
	 */
	float GetVelocity() const { return Velocity_; }


	/**
	 * 2D World ���� ī�޶��� �ӷ��� �����մϴ�.
	 * 
	 * @param InVelocity - ������ ī�޶��� �ӷ��Դϴ�.
	 */
	void SetVelocity(const float& InVelocity) { Velocity_ = InVelocity; }


	/**
	 * �ʴ��� ��Ÿ �ð��� ��ŭ ī�޶� �����Դϴ�.
	 *
	 * @param InDeltaSeconds - ī�޶� ������ �ʴ��� ��Ÿ �ð� ���Դϴ�.
	 */
	void Move(float InDeltaSeconds);


	/**
	 * �Է� ���� ���� ��ǥ�� ī�޶� �������� ������ ��ǥ�� ��ȯ�մϴ�.
	 * ��, ���� ��ǥ => ī�޶� ��ǥ => ������ ��ǥ �� ��ȯ�մϴ�.
	 * 
	 * @param InWorldPosition - ��ȯ�� ���� ��ǥ�Դϴ�.
	 * 
	 * @return ��ȯ�� ������ ��ǥ�� ��ȯ�մϴ�.
	 */
	Vec2f ConvertToWindowPosition(const Vec2f& InWorldPosition);


private:
	/**
	 * 2D ���� ���� ī�޶� ���� ��ġ�Դϴ�.
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