#pragma once

#include <Component.h>

class World;


/**
 * 게임 오브젝트의 물리 처리를 수행하는 컴포넌트입니다.
 */
class PhysicComponent : public Component
{
public:
	/**
	 * 물리 처리 컴포넌트의 생성자입니다.
	 * 
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 */
	explicit PhysicComponent(GameObject* InObject) : Component(InObject) { }


	/**
	 * 물리 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~PhysicComponent() {}


	/**
	 * 물리 처리 컴포넌트의 복사 생성자 및 대입연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(PhysicComponent);


	/**
	 * 물리 처리 컴포넌트를 업데이트합니다.
	 * 
	 * @param InWorld - 2D 게임 월드입니다.
	 * @param InDeltaSeconds - 초단위 델타 시간 값입니다.
	 */
	virtual void Tick(World& InWorld, float InDeltaSeconds) = 0;
};