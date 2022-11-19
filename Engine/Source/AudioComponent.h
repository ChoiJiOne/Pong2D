#pragma once

#include <Component.h>


/**
 * ���� ������Ʈ�� ����� ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class AudioComponent : public Component
{
public:
	/**
	 * ����� ó���� �����ϴ� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 */
	explicit AudioComponent(GameObject* InObject) : Component(InObject) { }


	/**
	 * ����� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~AudioComponent() {}


	/**
	 * ����� ó�� ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(AudioComponent);


	/**
	 * ����� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 */
	virtual void Tick() = 0;
};