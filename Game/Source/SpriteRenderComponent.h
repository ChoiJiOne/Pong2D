#pragma once

#include <RenderComponent.h>


/**
 * 스프라이트의 렌더링 처리를 수행하는 컴포넌트입니다.
 */
class SpriteRenderComponent : public RenderComponent
{
public:
	/**
	 * 스프라이트의 렌더링 처리를 수행하는 컴포넌트의 생성자입니다.
	 *
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 * @param InSpriteKey - 렌더링할 스프라이트의 텍스처 키 값입니다.
	 */
	explicit SpriteRenderComponent(GameObject* InObject, const std::size_t& InSpriteKey) 
		: RenderComponent(InObject) 
	{
		SpriteKey_ = InSpriteKey;
	}


	/**
	 * 스프라이트의 렌더링 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~SpriteRenderComponent() {}


	/**
	 * 스프라이트의 렌더링 처리 컴포넌트의 복사 생성자 및 대입연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpriteRenderComponent);


	/**
	 * 스프라이트의 렌더링 처리 컴포넌트를 업데이트합니다.
	 *
	 * @param InRenderer - 렌더링 처리 클래스의 인스턴스입니다.
	 * @param InCamera - 카메라 클래스의 인스턴스입니다.
	 */
	virtual void Tick(Renderer& InRenderer, Camera& InCamera) override;


private:
	/**
	 * 렌더링을 처리할 스프라이트 텍스처의 키 값입니다.
	 */
	std::size_t SpriteKey_;
};