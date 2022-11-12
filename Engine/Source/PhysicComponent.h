#pragma once

class GameObject;
class World;


/**
 * ���� ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class PhysicComponent
{
public:
	/**
	 * ���� ó�� ������Ʈ�� ����Ʈ �������Դϴ�.
	 */
	PhysicComponent() = default;


	/**
	 * ���� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~PhysicComponent() {}


	/**
	 * ���� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @param InObject - ���� ó���� ������ ���� ������Ʈ�Դϴ�.
	 * @param InWorld - 2D ���� �����Դϴ�.
	 * @param InDeltaSeconds - �ʴ��� ��Ÿ �ð� ���Դϴ�.
	 */
	virtual void Tick(GameObject& InObject, World& InWorld, float InDeltaSeconds) = 0;
};