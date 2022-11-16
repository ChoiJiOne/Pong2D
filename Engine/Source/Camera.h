#pragma once

#include "RigidBody.h"
#include "Vector.h"


/**
 * 2D World ���� ī�޶��Դϴ�.
 */
class Camera : public RigidBody
{
public:
	/**
	 * 2D World �� ī�޶��� ����Ʈ �������Դϴ�.
	 * �̶�, ����Ʈ �����ڿ����� �ʱ�ȭ�� �������� �����Ƿ�, ����ϱ� ���� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Camera() = default;


	/**
	 * 2D World ���� ī�޶� �������Դϴ�.
	 * �� �����ڸ� ȣ���ϸ� ī�޶�� 2D World�� ������ ��ġ�˴ϴ�.
	 * 
	 * @param InPosition - 2D World ���� ī�޶� ��ġ�Դϴ�.
	 * @param InWidth - ī�޶��� ���� ũ���Դϴ�.
	 * @param InHeight - ī�޶��� ���� ũ���Դϴ�.
	 * @param InRotate - ī�޶��� �̵� �����Դϴ�.
	 * @param InVelocity - ī�޶��� �̵� �ӷ��Դϴ�.
	 * @param bCanMove - ī�޶��� �̵� �����Դϴ�.
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
	 * World ���� 2D ī�޶� ���� �Ҹ����Դϴ�.
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
	Vec2f GetPosition() const { return RigidBody::GetCenter(); }


	/**
	 * 2D World ���� ī�޶��� ��ġ�� �����մϴ�.
	 * 
	 * @param InPosition - ������ 2D World ���� ī�޶� ��ġ�Դϴ�.
	 */
	void SetPosition(const Vec2f& InPosition) { RigidBody::SetCenter(InPosition); }


	/**
	 * �ʴ��� ��Ÿ �ð��� ��ŭ ī�޶� �����Դϴ�.
	 * 
	 * @param InDeltaSeconds - ī�޶� ������ �ʴ��� ��Ÿ �ð� ���Դϴ�.
	 */
	void Move(float InDeltaSeconds);
};