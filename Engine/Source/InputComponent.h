#pragma once

#include <Component.h>

class Input;


/**
 * ���� ������Ʈ�� �Է� ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class InputComponent : public Component
{
public:
	/**
	 * �Է� ó�� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 */
	explicit InputComponent(GameObject* InObject) : Component(InObject) { }


	/**
	 * �Է� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~InputComponent() {}


	/**
	 * �Է� ó�� ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(InputComponent);


	/**
	 * �Է� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @param InInput - �Է� ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	 */
	virtual void Tick(Input& InInput) = 0;
};