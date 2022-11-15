#pragma once

#include "PhysicComponent.h"


/**
 * �÷��̾��� ���� ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class PlayerPhysicComponent : public PhysicComponent
{
public:
	/**
	 * �÷��̾��� ���� ó�� ������Ʈ�� �������Դϴ�.
	 *
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 */
	explicit PlayerPhysicComponent(GameObject* InObject) : PhysicComponent(InObject) { }


	/**
	 * �÷��̾��� ���� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~PlayerPhysicComponent() {}


	/**
	 * �÷��̾��� ���� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InWorld - 2D ���� �����Դϴ�.
	 * @param InDeltaSeconds - �ʴ��� ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Tick(World& InWorld, float InDeltaSeconds) override;
};