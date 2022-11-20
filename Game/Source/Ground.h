#pragma once

#include <GameObject.h>


/**
 * Pong2D ���� �׶��� Ŭ�����Դϴ�.
 */
class Ground : public GameObject
{
public:
	/**
	 * Pong2D ���� �׶����� �������Դϴ�.
	 *
	 * @param InWorld - ���� �׶��尡 ��ġ�� �����Դϴ�.
	 * @param InSignature - ���� �׶����� �ñ״�ó �ؽ� ���Դϴ�.
	 * @param InPosition - ���� �׶����� ȭ��� ��ġ�Դϴ�.
	 * @param InWidth - ���� �׶����� ���� ũ���Դϴ�.
	 * @param InHeight - ���� �׶����� ���� ũ���Դϴ�.
	 */
	explicit Ground(
		World* InWorld,
		const std::size_t& InSignature,
		const Vec2f& InPosition,
		const float& InWidth,
		const float& InHeight
	);


	/**
	 * Pong2D ���� �׶����� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Ground();


	/**
	 * ���� �׶����� ���� �����ڿ� ���� �����ڸ� ���������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Ground);


	/**
	 * ���� �׶��带 ������Ʈ�մϴ�.
	 *
	 * @param InInput - ������ �Է� ó�� �ν��Ͻ��Դϴ�.
	 * @param InDeltaTime - �ʴ��� ��Ÿ �ð��� �Դϴ�.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * ���� �׶��带 ȭ�鿡 �׸��ϴ�.
	 *
	 * @param InGraphics - ������ ������ ó���� ���� �������Դϴ�.
	 * @param InCamera - ������ �þ� ó���� ���� ī�޶��Դϴ�.
	 */
	virtual void Render(Renderer& InRenderer, Camera& InCamera) override;
};