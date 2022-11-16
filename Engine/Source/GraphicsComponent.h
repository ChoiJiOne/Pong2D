#pragma once

#include "Component.h"

class Graphics;
class Camera;


/**
 * ���� ������Ʈ�� ������ ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class GraphicsComponent : public Component
{
public:
	/**
	 * ������ ó���� �����ϴ� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 */
	explicit GraphicsComponent(GameObject* InObject) : Component(InObject) { }


	/**
	 * ������ ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~GraphicsComponent() {}


	/**
	 * ������ ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @param InGraphics - ������ ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	 * @param InCamera - ī�޶� Ŭ������ �ν��Ͻ��Դϴ�.
	 */
	virtual void Tick(Graphics& InGraphics, Camera& InCamera) = 0;
};