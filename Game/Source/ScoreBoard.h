#pragma once

#include <Color.h>
#include <GameObject.h>


/**
 * Pong2D ������ �÷��̾���� Ȯ���� ������ ��Ÿ���� ���ھ� �����Դϴ�.
 */
class ScoreBoard : public GameObject
{
public:
	/**
	 * Pong2D ������ ���ھ� ���� �������Դϴ�.
	 * 
	 * @param InWorld - ���� ���ھ� ���尡 ��ġ�� �����Դϴ�.
	 * @param InSignature - ���� ���ھ� ������ �ñ״�ó �ؽ� ���Դϴ�.
	 * @param InPosition - ���� ���ھ� ������ ��ġ�Դϴ�.
	 * @param InWidth - ���� ���ھ� ������ ���� ũ���Դϴ�.
	 * @param InHeight - ���� ���ھ� ������ ���� ũ���Դϴ�.
	 * @param InColor - ���� ���ھ� ������ �����Դϴ�.
	 */
	explicit ScoreBoard(
		World* InWorld, 
		const std::size_t& InSignature,
		const Vec2f& InPosition,
		const float& InWidth,
		const float& InHeight,
		const LinearColor& InColor
	);


	/**
	 * Pong2D ������ ���ھ� ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~ScoreBoard();


	/**
	 * ���� ���ھ� ������ ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ScoreBoard);


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


	/**
	 * ���ھ� ���带 �ʱ�ȭ�մϴ�.
	 */
	void Reset() { Player1Score_ = 0, Player2Score_ = 0; }


	/**
	 * �÷��̾�1�� ������ ����ϴ�.
	 * 
	 * @return �÷��̾�1�� ������ ��ȯ�մϴ�.
	 */
	int32_t GetPlayer1Score() const { return Player1Score_; }


	/**
	 * �÷��̾�2�� ������ ����ϴ�.
	 * 
	 * @return �÷��̾�2�� ������ ��ȯ�մϴ�.
	 */
	int32_t GetPlayer2Score() const { return Player2Score_; }


private:
	/**
	 * �÷��̾�1�� �����Դϴ�.
	 */
	int32_t Player1Score_ = 0;


	/**
	 * �÷��̾�2�� �����Դϴ�.
	 */
	int32_t Player2Score_ = 0;
};