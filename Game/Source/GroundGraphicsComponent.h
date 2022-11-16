#pragma once

#include "GraphicsComponent.h"


/**
 * 그라운드의 렌더링 처리를 수행하는 컴포넌트입니다.
 */
class GroundGraphicsComponent : public GraphicsComponent
{
public:
	/**
	 * 그라운드의 렌더링 처리를 수행하는 컴포넌트의 생성자입니다.
	 *
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 */
	explicit GroundGraphicsComponent(GameObject* InObject) : GraphicsComponent(InObject) { }


	/**
	 * 그라운드의 렌더링 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~GroundGraphicsComponent() {}


	/**
	 * 렌더링 처리 컴포넌트를 업데이트합니다.
	 *
	 * @param InGraphics - 렌더링 처리 클래스의 인스턴스입니다.
	 * @param InCamera - 카메라 클래스의 인스턴스입니다.
	 */
	virtual void Tick(Graphics& InGraphics, Camera& InCamera) override;
};