#pragma once

#include <Color.h>
#include <RenderComponent.h>


/**
 * ���� �׶����� ������ ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class GroundRenderComponent : public RenderComponent
{
public:
	/**
	 * ���� �׶����� ������ ó���� �����ϴ� ������Ʈ�� �������Դϴ�.
	 *
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 * @param InColor - �������� �׶����� ���� ���Դϴ�.
	 */
	explicit GroundRenderComponent(GameObject* InObject, const LinearColor& InColor)
		: RenderComponent(InObject)
	{
		Color_ = InColor;
	}


	/**
	 * ���� �׶����� ������ ó���� �����ϴ� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~GroundRenderComponent() {}


	/**
	 * ���� �׶����� ������ ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InRenderer - ������ ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	 * @param InCamera - ī�޶� Ŭ������ �ν��Ͻ��Դϴ�.
	 */
	virtual void Tick(Renderer& InRenderer, Camera& InCamera) override;


private:
	/**
	 * �׶����� �ܰ� �����Դϴ�.
	 */
	LinearColor Color_;
};