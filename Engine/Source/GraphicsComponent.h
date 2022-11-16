#pragma once

#include "Component.h"

class Graphics;
class Camera;


/**
 * 게임 오브젝트의 렌더링 처리를 수행하는 컴포넌트입니다.
 */
class GraphicsComponent : public Component
{
public:
	/**
	 * 렌더링 처리를 수행하는 컴포넌트의 생성자입니다.
	 * 
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 */
	explicit GraphicsComponent(GameObject* InObject) : Component(InObject) { }


	/**
	 * 렌더링 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~GraphicsComponent() {}


	/**
	 * 렌더링 처리 컴포넌트를 업데이트합니다.
	 * 
	 * @param InGraphics - 렌더링 처리 클래스의 인스턴스입니다.
	 * @param InCamera - 카메라 클래스의 인스턴스입니다.
	 */
	virtual void Tick(Graphics& InGraphics, Camera& InCamera) = 0;
};