#pragma once

#include <GameObject.h>


/**
 * Pong2D ���� �÷��̾��Դϴ�.
 */
class Player : public GameObject
{
public:
	/**
	 * �÷��̾� Ÿ���Դϴ�.
	 * PLAYER1�� ���� �÷��̾��̰�, PLAYER2�� ������ �÷��̾��Դϴ�.
	 */
	enum class EType : int32_t
	{
		PLAYER1 = 0,
		PLAYER2 = 1,
	};


public:
	/**
	 * Pong2D ���� �÷��̾��� �������Դϴ�.
	 *
	 * @param InWorld - ���� �÷��̾ ��ġ�� �����Դϴ�.
	 * @param InSignature - ���� �÷��̾��� �ñ״�ó �ؽ� ���Դϴ�.
	 * @param InType - ���� �÷��̾��� Ÿ���Դϴ�.
	 * @param InPosition - ���� �÷��̾��� ȭ��� ��ġ�Դϴ�.
	 * @param InWidth - ���� �÷��̾��� ���� ũ���Դϴ�.
	 * @param InHeight - ���� �÷��̾��� ���� ũ���Դϴ�.
	 * @param InVelocity - ���� �÷��̾��� �ӵ��Դϴ�.
	 *
	 */
	explicit Player(
		World* InWorld,
		const std::size_t& InSignature,
		const EType& InType,
		const Vec2f& InPosition,
		const float& InWidth,
		const float& InHeight,
		const float& InVelocity
	);


	/**
	 * Pong2D ���� �÷��̾��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Player();


	/**
	 * ���� �÷��̾��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Player);


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
	 * �÷��̾��� Ÿ���� ����ϴ�.
	 *
	 * @return �÷��̾��� Ÿ���� ��ȯ�մϴ�.
	 */
	EType GetType() const { return Type_; }


private:
	/**
	 * ���� �÷��̾��� Ÿ���Դϴ�.
	 */
	EType Type_;
};