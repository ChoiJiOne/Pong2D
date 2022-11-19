#pragma once

#include <Component.h>

class World;


/**
 * ���� ������Ʈ�� ���� ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class PhysicComponent : public Component
{
public:
	/**
	 * ���� ó�� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 */
	explicit PhysicComponent(GameObject* InObject) : Component(InObject) { }


	/**
	 * ���� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~PhysicComponent() {}


	/**
	 * ���� ó�� ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(PhysicComponent);


	/**
	 * ���� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @param InWorld - 2D ���� �����Դϴ�.
	 * @param InDeltaSeconds - �ʴ��� ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Tick(World& InWorld, float InDeltaSeconds) = 0;
};