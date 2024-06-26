#pragma once

#include <Component.h>

class Input;


/**
 * 게임 오브젝트의 입력 처리를 수행하는 컴포넌트입니다.
 */
class InputComponent : public Component
{
public:
	/**
	 * 입력 처리 컴포넌트의 생성자입니다.
	 * 
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 */
	explicit InputComponent(GameObject* InObject) : Component(InObject) { }


	/**
	 * 입력 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~InputComponent() {}


	/**
	 * 입력 처리 컴포넌트의 복사 생성자 및 대입연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(InputComponent);


	/**
	 * 입력 처리 컴포넌트를 업데이트합니다.
	 * 
	 * @param InInput - 입력 처리 클래스의 인스턴스입니다.
	 */
	virtual void Tick(Input& InInput) = 0;
};