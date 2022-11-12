#pragma once

#include <array>

#include "Vector.h"


/**
 * ������Ʈ�� �ٵ��Դϴ�.
 * �̶�, ������Ʈ �ٵ�� AABB ������� ȸ������ �ʽ��ϴ�.
 */
class Body
{
public:
	/**
	 * ������Ʈ �ٵ��� �⺻ �������Դϴ�.
	 * �̶�, ����Ʈ �����ڿ��� �ʱ�ȭ�� �������� �����Ƿ�, ����ϱ� ���� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Body() = default;


	/**
	 * ������Ʈ�� �ٵ��� �������Դϴ�.
	 * 
	 * @param InCenter - ������Ʈ �ٵ��� �߽� ��ǥ�Դϴ�.
	 * @param InWidth - ������Ʈ �ٵ��� ���� ũ���Դϴ�.
	 * @param InHeight - ������Ʈ �ٵ� ���� ũ���Դϴ�.
	 * @param InRotate - ������Ʈ �ٵ��� �̵� ���� �����Դϴ�.
	 * @param InVelocity - ������Ʈ �ٵ��� �ӷ��Դϴ�.
	 * @param bCanMove - ������Ʈ �ٵ��� �̵� �����Դϴ�.
	 */
	explicit Body(
		const Vec2f& InCenter, 
		const float& InWidth, 
		const float& InHeight,
		const float& InRotate = 0.0f,
		const float& InVelocity = 0.0f,
		bool bCanMove = false
	);
	
	
	/**
	 * ������Ʈ �ٵ��� ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	Body(Body&& InInstance) noexcept;


	/**
	 * ������Ʈ �ٵ��� ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	Body(const Body& InInstance) noexcept;


	/**
	 * ������Ʈ �ٵ��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Body();


	/**
	 * ������Ʈ �ٵ��� ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Body& operator=(Body&& InInstance) noexcept;


	/**
	 * ������Ʈ �ٵ��� ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	Body& operator=(const Body& InInstance) noexcept;


	/**
	 * ������Ʈ �ٵ��� �߽� ��ǥ�� ����ϴ�.
	 *
	 * @return ������Ʈ �ٵ��� �߽� ��ǥ�� ��ȯ�մϴ�.
	 */
	Vec2f GetCenter() const { return Center_; }


	/**
	 * ������Ʈ �ٵ��� �߽� ��ǥ�� �����մϴ�.
	 *
	 * @param InCenter - ������ ������Ʈ �ٵ��� �߽���ǥ�Դϴ�.
	 */
	void SetCenter(const Vec2f& InCenter);


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
	 * ������Ʈ �ٵ��� ��� �������� ����ϴ�.
	 * 
	 * @return ������Ʈ �ٵ��� ��� �������� ��ȯ�մϴ�.
	 */
	const std::array<Vec2f, 4>& GetBoundingPositions() const { return BoundingPositions_; }


	/**
	 * �ٸ� ������Ʈ �ٵ�� �浹�ϴ��� �˻��մϴ�.
	 * 
	 * @param InBody - �˻縦 ������ �ٸ� ������Ʈ�� ��ü�Դϴ�.
	 * 
	 * @return �ٸ� ������Ʈ�� �浹�Ѵٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsCollision(const Body& InBody);


private:
	/**
	 * ������Ʈ �ٵ��� ����� �߽� ��ǥ�Դϴ�.
	 */
	Vec2f Center_;


	/**
	 * ������Ʈ �ٵ��� ������ �����Դϴ�.
	 */
	bool bCanMove_ = true;


	/**
	 * ������Ʈ �ٵ��� ���� ũ���Դϴ�.
	 */
	float Width_ = 0;


	/**
	 * ������Ʈ �ٵ��� ���� ũ���Դϴ�.
	 */
	float Height_ = 0;


	/**
	 * ������Ʈ �ٵ��� ����� �̵� ���� �����Դϴ�.
	 */
	float Rotate_ = 0.0f;


	/**
	 * ������Ʈ �ٵ��� �ӷ��Դϴ�.
	 */
	float Velocity_ = 0.0f;


	/**
	 * ������Ʈ�� ��� �������Դϴ�.
	 */
	std::array<Vec2f, 4> BoundingPositions_;
};