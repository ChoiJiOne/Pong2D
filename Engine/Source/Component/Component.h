#pragma once

#include "Misc/MacroUtils.h"

class GameObject;


/**
 * ������Ʈ�� �����ϴ� ������Ʈ�Դϴ�.
 * �̶�, �� Ŭ������ �������̽� Ŭ�����Դϴ�.
 */
class Component
{
public:
	/**
	 * ������Ʈ�� �����ϴ� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 */
	explicit Component(GameObject* InObject) : Object_(InObject) {}


	/**
	 * ������Ʈ�� �����ϴ� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Component() {}


	/**
	 * ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Component);


	/**
	 * �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �����͸� ����ϴ�.
	 * 
	 * @return �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �����͸� ��ȯ�մϴ�.
	 */
	GameObject* GetGameObject() { return Object_; }


private:
	/**
	 * �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�Դϴ�.
	 */
	GameObject* Object_ = nullptr;
};