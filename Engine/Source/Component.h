#pragma once

class GameObject;


/**
 * 오브젝트가 소유하는 컴포넌트입니다.
 * 이때, 이 클래스는 인터페이스 클래스입니다.
 */
class Component
{
public:
	/**
	 * 오브젝트가 소유하는 컴포넌트의 생성자입니다.
	 * 
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 */
	explicit Component(GameObject* InObject) : Object_(InObject) {}


	/**
	 * 오브젝트가 소유하는 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~Component() {}


protected:
	/**
	 * 이 컴포넌트를 소유하고 있는 게임 오브젝트입니다.
	 */
	GameObject* Object_ = nullptr;
};