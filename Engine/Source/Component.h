#pragma once

#include "Macro.h"

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


protected:
	/**
	 * �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�Դϴ�.
	 */
	GameObject* Object_ = nullptr;
};