#pragma once

#include "InputComponent.h"


/**
 * �÷��̾��� �Է� ó�� ������Ʈ�Դϴ�.
 */
class PlayerInputComponent : public InputComponent
{
public:
	/**
	 * �÷��̾��� �Է� ó�� ������Ʈ�� �������Դϴ�.
	 *
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 */
	explicit PlayerInputComponent(GameObject* InObject) : InputComponent(InObject) { }


	/**
	 * �÷��̾��� �Է� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~PlayerInputComponent() {}


	/**
	 * �÷��̾��� �Է� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InInput - �Է� ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	 */
	virtual void Tick(Input& InInput) override;
};