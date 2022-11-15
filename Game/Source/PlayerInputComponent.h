#pragma once

#include "InputComponent.h"


/**
 * 플레이어의 입력 처리 컴포넌트입니다.
 */
class PlayerInputComponent : public InputComponent
{
public:
	/**
	 * 플레이어의 입력 처리 컴포넌트의 생성자입니다.
	 *
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 */
	explicit PlayerInputComponent(GameObject* InObject) : InputComponent(InObject) { }


	/**
	 * 플레이어의 입력 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~PlayerInputComponent() {}


	/**
	 * 플레이어의 입력 처리 컴포넌트를 업데이트합니다.
	 *
	 * @param InInput - 입력 처리 클래스의 인스턴스입니다.
	 */
	virtual void Tick(Input& InInput) override;
};