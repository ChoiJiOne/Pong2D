#pragma once

#include <GameObject.h>


/**
 * Pong2D ���� ���Դϴ�.
 */
class Ball : public GameObject
{
public:
	/**
	 * Pong2D ���� ���� �������Դϴ�.
	 *
	 * @param InWorld - ���� ���� ��ġ�� �����Դϴ�.
	 * @param InSignature - ���� ���� �ñ״�ó �ؽ� ���Դϴ�.
	 * @param InPosition - ���� ���� ȭ��� ��ġ�Դϴ�.
	 * @param InRadius - ���� ���� ������ ũ���Դϴ�.
	 * @param InVelocity - ���� ���� �ӵ��Դϴ�.
	 *
	 */
	explicit Ball(
		World* InWorld,
		const std::size_t& InSignature,
		const Vec2f& InPosition,
		const float& InRadius,
		const float& InVelocity
	);


	/**
	 * Pong2D ���� �÷��̾��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Ball();


	/**
	 * ���� ���� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Ball);


	/**
	 * ���� ���� ������Ʈ�մϴ�.
	 *
	 * @param InInput - ������ �Է� ó���� ���� �Է��Դϴ�.
	 * @param InDeltaTime - �ʴ��� ��Ÿ �ð��� �Դϴ�.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * ���� ���� ȭ�鿡 �׸��ϴ�.
	 *
	 * @param InGraphics - ������ ������ ó���� ���� �������Դϴ�.
	 * @param InCamera - ������ �þ� ó���� ���� ī�޶��Դϴ�.
	 */
	virtual void Render(Renderer& InRenderer, Camera& InCamera) override;
};