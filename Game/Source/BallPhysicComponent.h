#pragma once

#include "PhysicComponent.h"


/**
 * ���� ���� ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class BallPhysicComponent : public PhysicComponent
{
public:
	/**
	 * ���� ���� ó�� ������Ʈ�� �������Դϴ�.
	 *
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 */
	explicit BallPhysicComponent(GameObject* InObject) : PhysicComponent(InObject) { }


	/**
	 * ���� ���� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~BallPhysicComponent() {}


	/**
	 * ���� ���� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InWorld - 2D ���� �����Դϴ�.
	 * @param InDeltaSeconds - �ʴ��� ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Tick(World& InWorld, float InDeltaSeconds) override;


private:
	/**
	 * ���� �̵� ������ �������� �����Դϴ�.
	 * 
	 * @param InDeltaSeconds - �ʴ��� ��Ÿ �ð� ���Դϴ�.
	 */
	void Move(float InDeltaSeconds);


	/**
	 * ���� �÷��̾���� �浹 �˻縦 �����մϴ�.
	 * 
	 * @param InWorld - ���� �÷��̾ ��ġ�� 2D �����Դϴ�. 
	 */
	void CheckToPlayerCollision(World& InWorld);


	/**
	 * ���� �׶����� ���� �浹 �˻縦 �����մϴ�.
	 * 
	 * @param InWorld - ���� ���� ��ġ�� 2D �����Դϴ�.
	 */
	void CheckToWallCollision(World& InWorld);
};