#pragma once

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


protected:
	/**
	 * �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�Դϴ�.
	 */
	GameObject* Object_ = nullptr;
};