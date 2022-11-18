#pragma once

#include "Component.h"

class Renderer;
class Camera;


/**
 * ���� ������Ʈ�� ������ ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class RenderComponent : public Component
{
public:
	/**
	 * ������ ó���� �����ϴ� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 */
	explicit RenderComponent(GameObject* InObject) : Component(InObject) { }


	/**
	 * ������ ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~RenderComponent() {}


	/**
	 * ������ ó�� ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(RenderComponent);


	/**
	 * ������ ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @param InRenderer - ������ ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	 * @param InCamera - ī�޶� Ŭ������ �ν��Ͻ��Դϴ�.
	 */
	virtual void Tick(Renderer& InRenderer, Camera& InCamera) = 0;
};