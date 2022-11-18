#pragma once

#include "Misc/MacroUtils.h"

#include <list>

class GameObject;


/**
 * ���� ������Ʈ�� ��ġ�ϴ� 2D ���� ���� Ŭ�����Դϴ�.
 */
class World
{
public:
	/**
	 * 2D ���� ������ ����Ʈ �������Դϴ�.
	 */
	World() = default;


	/**
	 * 2D ���� ���� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~World();


	/**
	 * ��������� ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(World);


	/**
	 * 2D ���� ���忡 ������Ʈ�� �߰��մϴ�.
	 * 
	 * @param InObject - 2D ���忡 �߰��� ������Ʈ�Դϴ�.
	 */
	void AddOjbect(GameObject* InObject);


	/**
	 * 2D ���� ���忡 ������Ʈ�� �����ϴ��� Ȯ���մϴ�.
	 * 
	 * @param InObject - �����ϴ��� Ȯ���� ������Ʈ�Դϴ�.
	 * 
	 * @return 2D ���� ���忡 �����Ѵٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsExistObject(GameObject* InObject);


	/**
	 * 2D ���� ���忡 ������Ʈ�� �����մϴ�.
	 * �̶�, �ش� ������Ʈ�� �������� �ʴ´ٸ� �ƹ� ���۵� ���� �ʽ��ϴ�.
	 * 
	 * @param InObject - 2D ���忡�� �߰��� ������Ʈ�Դϴ�.
	 */
	void RemoveObject(GameObject* InObject);


	/**
	 * 2D ���� ���忡 �����ϴ� ������Ʈ�� ����Ʈ�� ����ϴ�.
	 * 
	 * @return 2D ���� ���忡 �����ϴ� ������Ʈ�� ����Ʈ�� ��ȯ�մϴ�.
	 */
	const std::list<GameObject*>& GetAllObject() const { return GameObjects_; }


private:
	/**
	 * ���� ���� ���� �����ϴ� ���� ������Ʈ�Դϴ�.
	 */
	std::list<GameObject*> GameObjects_;
};