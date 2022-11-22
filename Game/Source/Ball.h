#pragma once

#include <GameObject.h>


/**
 * Pong2D ���� ���Դϴ�.
 */
class Ball : public GameObject
{
public:
	/**
	 * Ball�� �����Դϴ�.
	 * WAIT�� ���� ������ ���� ��� ���� �����̰�, MOVE�� ���� �����̰� �ִ� �����Դϴ�.
	 */
	enum class EState : int32_t
	{
		WAIT = 0,
		MOVE = 1
	};


public:
	/**
	 * Pong2D ���� ���� �������Դϴ�.
	 *
	 * @param InWorld - ���� ���� ��ġ�� �����Դϴ�.
	 * @param InSignature - ���� ���� �ñ״�ó �ؽ� ���Դϴ�.
	 * @param InPosition - ���� ���� ȭ��� ��ġ�Դϴ�.
	 * @param InRadius - ���� ���� ������ ũ���Դϴ�.
	 * @param InRotate - ���� ���� �̵� ���� ���Դϴ�.
	 * @param InVelocity - ���� ���� �ӵ��Դϴ�.
	 */
	explicit Ball(
		World* InWorld,
		const std::size_t& InSignature,
		const Vec2f& InPosition,
		const float& InRadius,
		const float& InRotate,
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


	/**
	 * ���� ���� ���¸� ����ϴ�.
	 * 
	 * @return ���� ���� ���¸� ��ȯ�մϴ�.
	 */
	EState GetCurrentState() const { return CurrentState_; }


	/**
	 * ���� ���� ���¸� �����մϴ�.
	 * 
	 * @param InState - ������ ���� �����Դϴ�.
	 */
	void SetCurrentState(const EState& InState) { CurrentState_ = InState; }


	/**
	 * ���� ���¸� �ʱ�ȭ�մϴ�.
	 */
	void Reset();


	/**
	 * ���� ������ �������� ����ϰ� �մϴ�.
	 */
	void Start();


private:
	/**
	 * ���� ���� �����Դϴ�.
	 */
	EState CurrentState_ = EState::WAIT;
};