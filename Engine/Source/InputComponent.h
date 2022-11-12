#pragma once

class GameObject;
class Input;


/**
 * �Է� ó���� �����ϴ� ������Ʈ�Դϴ�.
 * �� Ŭ������ �������̽� Ŭ�����Դϴ�.
 */
class InputComponent
{
public:
	/**
	 * �Է� ó�� ������Ʈ�� ����Ʈ �������Դϴ�.
	 */
	InputComponent() = default;


	/**
	 * �Է� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~InputComponent() {}


	/**
	 * �Է� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @param InObject - �Է�ó���� ������ ���� ������Ʈ�Դϴ�.
	 * @param InInput - �Է� ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	 */
	virtual void Tick(GameObject& InObject, Input& InInput) = 0;
};