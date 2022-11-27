#pragma once

#include <InputComponent.h>


/**
 * 공의 입력 처리 컴포넌트입니다.
 */
class BallInputComponent : public InputComponent
{
public:
	/**
	 * 공의 입력 처리 컴포넌트의 생성자입니다.
	 *
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 */
	explicit BallInputComponent(GameObject* InObject) : InputComponent(InObject) {}


	/**
	 * 공의 입력 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~BallInputComponent() {}


	/**
	 * 공의 입력 처리 컴포넌트를 업데이트합니다.
	 *
	 * @param InInput - 입력 처리 클래스의 인스턴스입니다.
	 */
	virtual void Tick(Input& InInput) override;
};