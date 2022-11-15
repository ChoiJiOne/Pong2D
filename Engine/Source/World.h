#pragma once

#include "Macro.h"

#include <list>

class GameObject;


/**
 * ���� ������Ʈ�� ��ġ�ϴ� 2D ���� ���� Ŭ�����Դϴ�.
 */
class World
{
public:
	/**
	 * 2D ���� ���� Ŭ������ �������Դϴ�.
	 * 
	 * @param InWidth - 2D ���� ������ ���� ũ���Դϴ�.
	 * @param InHeight - 2D ���� ������ ���� ũ���Դϴ�.
	 */
	explicit World(const float& InWidth, const float& InHeight);


	/**
	 * 2D ���� ���� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~World();


	/**
	 * ��������� ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(World);


	/**
	 * 2D ���� ���忡 ������Ʈ�� �߰��մϴ�.
	 * 
	 * @param InObject - 2D ���忡 �߰��� ������Ʈ�Դϴ�.
	 */
	void AddOjbect(GameObject* InObject);


	/**
	 * 2D ���� ���忡 ������Ʈ�� �����ϴ��� Ȯ���մϴ�.
	 * 
	 * @param InObject - �����ϴ��� Ȯ���� ������Ʈ�Դϴ�.
	 * 
	 * @return 2D ���� ���忡 �����Ѵٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsExistObject(GameObject* InObject);


	/**
	 * 2D ���� ���忡 ������Ʈ�� �����մϴ�.
	 * �̶�, �ش� ������Ʈ�� �������� �ʴ´ٸ� �ƹ� ���۵� ���� �ʽ��ϴ�.
	 * 
	 * @param InObject - 2D ���忡�� �߰��� ������Ʈ�Դϴ�.
	 */
	void RemoveObject(GameObject* InObject);


	/**
	 * 2D ���� ������ ���� ũ�⸦ ����ϴ�.
	 * 
	 * @return 2D ���� ������ ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetWidth() const { return Width_; }


	/**
	 * 2D ���� ������ ���� ũ�⸦ ����ϴ�.
	 * 
	 * @return 2D ���� ������ ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	float GetHeight() const { return Height_; }


	/**
	 * 2D ���� ������ ���� ���� ũ�⸦ ����ϴ�.
	 * 
	 * @param OutWidth - 2D ���� ������ ���� ũ���Դϴ�.
	 * @param OutHeight - 2D ���� ������ ���� ũ���Դϴ�.
	 */
	void GetSize(float& OutWidth, float& OutHeight) const
	{
		OutWidth = Width_;
		OutHeight = Height_;
	}


	/**
	 * 2D ���� ���忡 �����ϴ� ������Ʈ�� ����Ʈ�� ����ϴ�.
	 * 
	 * @return 2D ���� ���忡 �����ϴ� ������Ʈ�� ����Ʈ�� ��ȯ�մϴ�.
	 */
	const std::list<GameObject*>& GetAllObject() const { return GameObjects_; }


private:
	/**
	 * ���� ���� ��ü�� ���� ũ���Դϴ�.
	 */
	float Width_ = 0;


	/**
	 * ���� ���� ��ü�� ���� ũ���Դϴ�.
	 */
	float Height_ = 0;


	/**
	 * ���� ���� ���� �����ϴ� ���� ������Ʈ�Դϴ�.
	 */
	std::list<GameObject*> GameObjects_;
};