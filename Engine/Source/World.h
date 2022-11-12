#pragma once

#include "Macro.h"

#include <list>

class GameObject;


/**
 * 게임 오브젝트가 위치하는 2D 게임 월드 클래스입니다.
 */
class World
{
public:
	/**
	 * 2D 게임 월드 클래스의 생성자입니다.
	 * 
	 * @param InWidth - 2D 게임 월드의 가로 크기입니다.
	 * @param InHeight - 2D 게임 월드의 세로 크기입니다.
	 */
	explicit World(const int32_t& InWidth, const int32_t& InHeight);


	/**
	 * 2D 게임 월드 클래스의 가상 소멸자입니다.
	 */
	virtual ~World();


	/**
	 * 명시적으로 복사 생성자와 대입 연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(World);


	/**
	 * 2D 게임 월드에 오브젝트를 추가합니다.
	 * 
	 * @param InObject - 2D 월드에 추가할 오브젝트입니다.
	 */
	void AddOjbect(GameObject* InObject);


	/**
	 * 2D 게임 월드에 오브젝트가 존재하는지 확인합니다.
	 * 
	 * @param InObject - 존재하는지 확인할 오브젝트입니다.
	 * 
	 * @return 2D 게임 월드에 존재한다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsExistObject(GameObject* InObject);


	/**
	 * 2D 게임 월드에 오브젝트를 삭제합니다.
	 * 이때, 해당 오브젝트가 존재하지 않는다면 아무 동작도 하지 않습니다.
	 * 
	 * @param InObject - 2D 월드에서 추가할 오브젝트입니다.
	 */
	void RemoveObject(GameObject* InObject);


	/**
	 * 2D 게임 월드의 가로 크기를 얻습니다.
	 * 
	 * @return 2D 게임 월드의 가로 크기를 반환합니다.
	 */
	int32_t GetWidth() const { return Width_; }


	/**
	 * 2D 게임 월드의 세로 크기를 얻습니다.
	 * 
	 * @return 2D 게임 월드의 세로 크기를 반환합니다.
	 */
	int32_t GetHeight() const { return Height_; }


	/**
	 * 2D 게임 월드의 가로 세로 크기를 얻습니다.
	 * 
	 * @param OutWidth - 2D 게임 월드의 가로 크기입니다.
	 * @param OutHeight - 2D 게임 월드의 세로 크기입니다.
	 */
	void GetSize(int32_t& OutWidth, int32_t& OutHeight) const
	{
		OutWidth = Width_;
		OutHeight = Height_;
	}


	/**
	 * 2D 게임 월드에 존재하는 오브젝트의 리스트를 얻습니다.
	 * 
	 * @return 2D 게임 월드에 존재하는 오브젝트의 리스트를 반환합니다.
	 */
	const std::list<GameObject*>& GetAllObject() const { return GameObjects_; }


private:
	/**
	 * 게임 월드 전체의 가로 크기입니다.
	 */
	int32_t Width_ = 0;


	/**
	 * 게임 월드 전체의 세로 크기입니다.
	 */
	int32_t Height_ = 0;


	/**
	 * 게임 월드 내에 존재하는 게임 오브젝트입니다.
	 */
	std::list<GameObject*> GameObjects_;
};