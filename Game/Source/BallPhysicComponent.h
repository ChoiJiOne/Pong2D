#pragma once

#include "PhysicComponent.h"


/**
 * 공의 물리 처리를 수행하는 컴포넌트입니다.
 */
class BallPhysicComponent : public PhysicComponent
{
public:
	/**
	 * 공의 물리 처리 컴포넌트의 생성자입니다.
	 *
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 */
	explicit BallPhysicComponent(GameObject* InObject) : PhysicComponent(InObject) { }


	/**
	 * 공의 물리 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~BallPhysicComponent() {}


	/**
	 * 공의 물리 처리 컴포넌트를 업데이트합니다.
	 *
	 * @param InWorld - 2D 게임 월드입니다.
	 * @param InDeltaSeconds - 초단위 델타 시간 값입니다.
	 */
	virtual void Tick(World& InWorld, float InDeltaSeconds) override;
};