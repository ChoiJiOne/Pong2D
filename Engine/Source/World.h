#pragma once

#include <Macro.h>

#include <unordered_map>

class GameObject;


/**
 * ���� ������Ʈ�� ��ġ�ϴ� 2D ���� ���� Ŭ�����Դϴ�.
 */
class World
{
public:
	/**
	 * 2D ���� ������ ����Ʈ �������Դϴ�.
	 */
	World() = default;


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
	 * @param InKey - 2D ���忡 �߰��� ������Ʈ�� Ű ���Դϴ�.
	 */
	void AddOjbect(GameObject* InObject, const std::size_t& InKey);


	/**
	 * 2D ���� ���忡 ������Ʈ�� �����ϴ��� Ȯ���մϴ�.
	 * 
	 * @param InKey - �����ϴ��� Ȯ���� ������Ʈ�� Ű ���Դϴ�.
	 * 
	 * @return 2D ���� ���忡 �����Ѵٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsExistObject(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� 2D ���� ������ ������Ʈ�� ����ϴ�.
	 * 
	 * @param InKey - 2D ���� ���忡 �ִ� ������Ʈ�� Ű ���Դϴ�.
	 * 
	 * @return Ű ���� �����ϴ� 2D ���� ������ ������Ʈ�� �����ϸ� ������Ʈ�� ������ ����, �׷��� ������ nullptr�� ��ȯ�մϴ�.
	 */
	GameObject* GetObject(const std::size_t& InKey);


	/**
	 * 2D ���� ���忡 ������Ʈ�� �����մϴ�.
	 * �̶�, �ش� ������Ʈ�� �������� �ʴ´ٸ� �ƹ� ���۵� ���� �ʽ��ϴ�.
	 * 
	 * @param InObject - 2D ���忡�� ������ ������Ʈ�� Ű ���Դϴ�.
	 */
	void RemoveObject(const std::size_t& InKey);


private:
	/**
	 * ���� ���� ���� �����ϴ� ���� ������Ʈ�Դϴ�.
	 */
	std::unordered_map<std::size_t, GameObject*> GameObjects_;
};