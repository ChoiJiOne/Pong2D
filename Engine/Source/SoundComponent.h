#pragma once

class GameObject;
class World;


/**
 * ���� ó���� �����ϴ� ������Ʈ�Դϴ�.
 * �� Ŭ������ �������̽� Ŭ�����Դϴ�.
 */
class SoundComponent
{
public:
	/**
	 * ���� ó���� �����ϴ� ������Ʈ�� ����Ʈ �������Դϴ�.
	 */
	SoundComponent() = default;


	/**
	 * ���� ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~SoundComponent() {}


	/**
	 * ���� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InObject - ���� ó���� ������ ���� ������Ʈ�Դϴ�.
	 */
	virtual void Tick(GameObject & InObject) = 0;
};