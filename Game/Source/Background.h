#pragma once

#include <GameObject.h>


/**
 * Pong2D ���� ��׶����Դϴ�.
 */
class Background : public GameObject
{
public:
	/**
	 * Pong2D ���� ��׶����� �������Դϴ�.
	 * 
	 * @param InWorld - ���� ��׶��尡 ��ġ�� �����Դϴ�.
	 * @param InSignature - ���� ��׶����� �ñ״�ó �ؽ� ���Դϴ�.
	 * @param InPosition - ���� ��׶����� �߽� ��ǥ�Դϴ�.
	 * @param InWidth - ���� ��׶����� ���� ũ���Դϴ�.
	 * @param InHeight - ���� ��׶����� ���� ũ���Դϴ�.
	 */
	Background(
		World* InWorld,
		const std::size_t& InSignature,
		const Vec2f& InPosition,
		const float& InWidth,
		const float& InHeight
	);


	/**
	 * Pong2D ���� ��׶����� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Background();


	/**
	 * ���� ��׶����� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Background);


	/**
	 * ���� �÷��̾ ������Ʈ�մϴ�.
	 *
	 * @param InInput - ������ �Է� ó���� ���� �Է��Դϴ�.
	 * @param InDeltaTime - �ʴ��� ��Ÿ �ð��� �Դϴ�.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * ���� �÷��̾ ȭ�鿡 �׸��ϴ�.
	 *
	 * @param InGraphics - ������ ������ ó���� ���� �������Դϴ�.
	 * @param InCamera - ������ �þ� ó���� ���� ī�޶��Դϴ�.
	 */
	virtual void Render(Renderer& InRenderer, Camera& InCamera) override;


	/**
	 * ��׶����� ���� ���� ũ�⸦ �����մϴ�.
	 * 
	 * @param InWidth - ������ ��׶����� ���� ũ���Դϴ�.
	 * @param InHeight - ������ ��׶����� ���� ũ���Դϴ�.
	 */
	void SetSize(const float& InWidth, const float& InHeight);
};