#pragma once

#include <Color.h>
#include <RenderComponent.h>


/**
 * ���� ���ھ� ������ ������ ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class ScoreBoardRenderComponent : public RenderComponent
{
public:
	/**
	 * ���� ���ھ� ������ ������ ó���� �����ϴ� ������Ʈ�� �������Դϴ�.
	 *
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 * @param InColor - ���ھ� ������ ���� ���Դϴ�.
	 */
	explicit ScoreBoardRenderComponent(GameObject* InObject, const LinearColor& InColor)
		: RenderComponent(InObject)
	{
		Color_ = InColor;
	}


	/**
	 * ���� ���ھ� ������ ������ ó���� �����ϴ� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~ScoreBoardRenderComponent() {}


	/**
	 * ���� ���ھ� ������ ������ ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InRenderer - ������ ó�� Ŭ������ �ν��Ͻ��Դϴ�.
	 * @param InCamera - ī�޶� Ŭ������ �ν��Ͻ��Դϴ�.
	 */
	virtual void Tick(Renderer& InRenderer, Camera& InCamera) override;


private:
	/**
	 * ���� ���ھ� ���忡 ǥ�õ� ������ �����Դϴ�.
	 */
	LinearColor Color_;
};