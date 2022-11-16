#pragma once

#include "GraphicsComponent.h"


/**
 * �÷��̾��� ������ ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class PlayerGraphicsComponent : public GraphicsComponent
{
public:
	/**
	 * �÷��̾��� ������ ó���� �����ϴ� ������Ʈ�� �������Դϴ�.
	 *
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 */
	explicit PlayerGraphicsComponent(GameObject* InObject) : GraphicsComponent(InObject) { }


	/**
	 * �÷��̾��� ������ ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~PlayerGraphicsComponent() {}


	/**
	 * ������ ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InGraphics - ������ ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	 * @param InCamera - ī�޶� Ŭ������ �ν��Ͻ��Դϴ�.
	 */
	virtual void Tick(Graphics& InGraphics, Camera& InCamera) override;
};