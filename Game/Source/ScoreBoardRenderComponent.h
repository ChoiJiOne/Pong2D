#pragma once

#include <Color.h>
#include <RenderComponent.h>


/**
 * 게임 스코어 보드의 렌더링 처리를 수행하는 컴포넌트입니다.
 */
class ScoreBoardRenderComponent : public RenderComponent
{
public:
	/**
	 * 게임 스코어 보드의 렌더링 처리를 수행하는 컴포넌트의 생성자입니다.
	 *
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 * @param InColor - 스코어 보드의 색상 값입니다.
	 */
	explicit ScoreBoardRenderComponent(GameObject* InObject, const LinearColor& InColor)
		: RenderComponent(InObject)
	{
		Color_ = InColor;
	}


	/**
	 * 게임 스코어 보드의 렌더링 처리를 수행하는 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~ScoreBoardRenderComponent() {}


	/**
	 * 게임 스코어 보드의 렌더링 처리 컴포넌트를 업데이트합니다.
	 *
	 * @param InRenderer - 렌더링 처리 클래스의 인스턴스입니다.
	 * @param InCamera - 카메라 클래스의 인스턴스입니다.
	 */
	virtual void Tick(Renderer& InRenderer, Camera& InCamera) override;


private:
	/**
	 * 게임 스코어 보드에 표시될 점수의 색상입니다.
	 */
	LinearColor Color_;
};