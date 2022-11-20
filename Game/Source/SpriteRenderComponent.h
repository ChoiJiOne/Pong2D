#pragma once

#include <RenderComponent.h>


/**
 * ��������Ʈ�� ������ ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class SpriteRenderComponent : public RenderComponent
{
public:
	/**
	 * ��������Ʈ�� ������ ó���� �����ϴ� ������Ʈ�� �������Դϴ�.
	 *
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 * @param InSpriteKey - �������� ��������Ʈ�� �ؽ�ó Ű ���Դϴ�.
	 */
	explicit SpriteRenderComponent(GameObject* InObject, const std::size_t& InSpriteKey) 
		: RenderComponent(InObject) 
	{
		SpriteKey_ = InSpriteKey;
	}


	/**
	 * ��������Ʈ�� ������ ó�� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~SpriteRenderComponent() {}


	/**
	 * ��������Ʈ�� ������ ó�� ������Ʈ�� ���� ������ �� ���Կ����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SpriteRenderComponent);


	/**
	 * ��������Ʈ�� ������ ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InRenderer - ������ ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	 * @param InCamera - ī�޶� Ŭ������ �ν��Ͻ��Դϴ�.
	 */
	virtual void Tick(Renderer& InRenderer, Camera& InCamera) override;


private:
	/**
	 * �������� ó���� ��������Ʈ �ؽ�ó�� Ű ���Դϴ�.
	 */
	std::size_t SpriteKey_;
};