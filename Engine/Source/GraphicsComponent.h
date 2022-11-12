#pragma once

class GameObject;
class Graphics;


/**
 * ������ ó���� �����ϴ� ������Ʈ�Դϴ�.
 * �� Ŭ������ �������̽� Ŭ�����Դϴ�.
 */
class GraphicsComponent
{
public:
	/**
	 * ������ ó���� �����ϴ� ������Ʈ�� ����Ʈ �������Դϴ�.
	 */
	GraphicsComponent() = default;


	/**
	 * ������ ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~GraphicsComponent() {}


	/**
	 * ������ ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 * 
	 * @param InObject - ������ ó���� ������ ���� ������Ʈ�Դϴ�.
	 * @param InInput - ������ ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	 */
	virtual void Tick(GameObject& InObject, Graphics& InGraphics) = 0;
};