#pragma once

#include <Component.h>

#include <Math.hpp>
#include <Vector.hpp>


/**
 * ���� ������Ʈ�� ������ �ٵ� ������Ʈ�Դϴ�.
 */
class RigidBodyComponent : public Component
{
public:
	/**
	 * ���� ������Ʈ�� �ٵ� Ÿ���Դϴ�.
	 */
	enum class EType : int32_t
	{
		NONE   = 0,
		AABB   = 1
	};


public:
	/**
	 * ���� ������Ʈ�� ������ �ٵ� ������Ʈ�� �������Դϴ�.
	 * �̶�, �� �����ڸ� ȣ���ϸ� �ٵ��� Ÿ���� AABB�� �����˴ϴ�.
	 * 
	 * @param InObject - �� ������Ʈ�� ������ ���� ������Ʈ�Դϴ�.
	 * @param InPosition - ������Ʈ �ٵ��� �߽� ��ǥ�Դϴ�.
	 * @param InWidth - ������Ʈ �ٵ��� ���� ũ���Դϴ�.
	 * @param InHeight - ������Ʈ �ٵ� ���� ũ���Դϴ�.
	 * @param InRotate - ������Ʈ �ٵ��� �̵� ���� �����Դϴ�.
	 * @param InVelocity - ������Ʈ �ٵ��� �ӷ��Դϴ�.
	 * @param bCanMove - ������Ʈ �ٵ��� �̵� �����Դϴ�.
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
	 * ���� ������Ʈ�� ������ �ٵ� ������Ʈ ���� �Ҹ����Դϴ�.
	 */
	virtual ~RigidBodyComponent() {}


	/**
	 * ���� ������Ʈ ������Ʈ�� ���� ������ �� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(RigidBodyComponent);


	/**
	 * ������Ʈ �ٵ��� Ÿ���� ����ϴ�.
	 * 
	 * @return ������Ʈ �ٵ��� Ÿ���� ��ȯ�մϴ�.
	 */
	EType GetType() const { return Type_; }


	/**
	 * ������Ʈ �ٵ��� �߽� ��ǥ�� ����ϴ�.
	 *
	 * @return ������Ʈ �ٵ��� �߽� ��ǥ�� ��ȯ�մϴ�.
	 */
	Vec2f GetPosition() const { return Position_; }


	/**
	 * ������Ʈ �ٵ��� �߽� ��ǥ�� �����մϴ�.
	 *
	 * @param InCenter - ������ ������Ʈ �ٵ��� �߽���ǥ�Դϴ�.
	 */
	void SetPosition(const Vec2f& InPosition);


	/**
	 * ������Ʈ �ٵ��� ������ ���θ� ����ϴ�.
	 *
	 * @return ������Ʈ �ٵ��� ������ ���θ� ��ȯ�մϴ�.
	 */
	bool CanMove() const { return bCanMove_; }


	/**
	 * ������Ʈ �ٵ��� ������ ���θ� �����մϴ�.
	 *
	 * @param ������ ������Ʈ �ٵ��� ������ �����Դϴ�.
	 */
	void SetCanMove(bool bCanMove) { bCanMove_ = bCanMove; }


	/**
	 * ������Ʈ �ٵ��� ���� ũ�⸦ ����ϴ�.
	 *
	 * @return ������Ʈ �ٵ��� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetWidth() const { return Width_; }


	/**
	 * ������Ʈ �ٵ��� ���� ũ�⸦ �����մϴ�.
	 *
	 * @param InWidth - ������ ������Ʈ �ٵ��� ���� ũ���Դϴ�.
	 */
	void SetWidth(const float& InWidth);


	/**
	 * ������Ʈ �ٵ��� ���� ���� ũ�⸦ ����ϴ�.
	 *
	 * @return ������Ʈ �ٵ��� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetHeight() const { return Height_; }


	/**
	 * ������Ʈ �ٵ��� ���� ũ�⸦ �����մϴ�.
	 *
	 * @param InHeight - ������ ������Ʈ �ٵ��� ���� ũ���Դϴ�.
	 */
	void SetHeight(const float& InHeight);


	/**
	 * ������Ʈ �ٵ��� ȸ�� ���� ����ϴ�.
	 * �̶�, ������ ���ʺй� �����Դϴ�.
	 *
	 * @return ������Ʈ �ٵ��� ȸ�� ���� ��ȯ�մϴ�.
	 */
	float GetRotate() const { return Rotate_; }


	/**
	 * ������Ʈ �ٵ��� �̵� ���� ���� �����մϴ�.
	 * �̶�, ������ ���ʺй� �����Դϴ�.
	 *
	 * @param InRotate - ������ ������Ʈ �ٵ��� �̵� ���� ���� �����Դϴ�.
	 */
	void SetRotate(const float& InRotate) { Rotate_ = InRotate; }


	/**
	 * ������Ʈ �ٵ��� �ӷ¸� ����ϴ�.
	 *
	 * @return ������Ʈ�� �ӷ¸� ��ȯ�մϴ�.
	 */
	float GetVelocity() const { return Velocity_; }


	/**
	 * ������Ʈ �ٵ��� �ӷ��� �����մϴ�.
	 *
	 * @param InVelocity - ������ ������Ʈ �ٵ��� �ӵ��Դϴ�.
	 */
	void SetVelocity(const float& InVelocity) { Velocity_ = InVelocity; }


	/**
	 * ������Ʈ �ٵ��� ��� ������ ����ϴ�.
	 *
	 * @return ������Ʈ �ٵ��� ��� ������ ��ȯ�մϴ�.
	 */
	const BoundingBox& GetBoundingBox() const { return BoundingBox_; }


	/**
	 * Ư�� ������Ʈ�� �ٵ�� �浹�ϴ��� Ȯ���մϴ�.
	 * �̶�, Ư�� ������Ʈ�� �ٵ� ���ο� �ִ� ���� �浹�� �������� �ʽ��ϴ�.
	 * 
	 * @param InRigidBody - �浹�ϴ��� Ȯ���� ������Ʈ �ٵ��Դϴ�.
	 * 
	 * @return Ư�� ������Ʈ�� �ٵ�� �浹�ϸ� true, �׷��� ������ fasle�� ��ȯ�մϴ�.
	 */
	bool IsCollision(RigidBodyComponent* InRigidBody);


private:
	/**
	 * ���� ������Ʈ�� ���� Ÿ���Դϴ�.
	 */
	EType Type_ = EType::NONE;


	/**
	 * ���� ������Ʈ�� ������ �����Դϴ�.
	 */
	bool bCanMove_ = true;


	/**
	 * ���� ������Ʈ�� ���� �� �߽� ��ǥ�Դϴ�.
	 */
	Vec2f Position_;


	/**
	 * ���� ������Ʈ�� ���� ũ���Դϴ�.
	 * �̶�, ���� Ÿ���� CIRCLE�̶�� Width�� Height ũ�Ⱑ �����մϴ�.
	 */
	float Width_ = 0.0f;


	/**
	 * ���� ������Ʈ�� ���� ũ���Դϴ�.
	 * �̶�, ���� Ÿ���� CIRCLE�̶�� Width�� Height ũ�Ⱑ �����մϴ�.
	 */
	float Height_ = 0.0f;


	/**
	 * ���� ������Ʈ�� ����� �̵� ���� �����Դϴ�.
	 */
	float Rotate_ = 0.0f;


	/**
	 * ���� ������Ʈ�� �ӷ��Դϴ�.
	 */
	float Velocity_ = 0.0f;


	/**
	 * ���� ������Ʈ�� ��� �����Դϴ�.
	 */
	BoundingBox BoundingBox_;
};