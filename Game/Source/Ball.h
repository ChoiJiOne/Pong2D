#pragma once

#include <GameObject.h>


/**
 * Pong2D 게임 공입니다.
 */
class Ball : public GameObject
{
public:
	/**
	 * Ball의 상태입니다.
	 * WAIT는 공이 움직임 없이 대기 중인 상태이고, MOVE는 공이 움직이고 있는 상태입니다.
	 */
	enum class EState : int32_t
	{
		WAIT = 0,
		MOVE = 1
	};


public:
	/**
	 * Pong2D 게임 공의 생성자입니다.
	 *
	 * @param InWorld - 게임 공이 위치할 월드입니다.
	 * @param InSignature - 게임 공의 시그니처 해쉬 값입니다.
	 * @param InPosition - 게임 공의 화면상 위치입니다.
	 * @param InRadius - 게임 공의 반지름 크기입니다.
	 * @param InRotate - 게임 공의 이동 방향 각입니다.
	 * @param InVelocity - 게임 공의 속도입니다.
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
	 * Pong2D 게임 플레이어의 가상 소멸자입니다.
	 */
	virtual ~Ball();


	/**
	 * 게임 공의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Ball);


	/**
	 * 게임 공을 업데이트합니다.
	 *
	 * @param InInput - 게임의 입력 처리를 위한 입력입니다.
	 * @param InDeltaTime - 초단위 델타 시값값 입니다.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * 게임 공을 화면에 그립니다.
	 *
	 * @param InGraphics - 게임의 렌더링 처리를 위한 렌더러입니다.
	 * @param InCamera - 게임의 시야 처리를 위한 카메라입니다.
	 */
	virtual void Render(Renderer& InRenderer, Camera& InCamera) override;


	/**
	 * 현재 공의 상태를 얻습니다.
	 * 
	 * @return 현재 공의 상태를 반환합니다.
	 */
	EState GetCurrentState() const { return CurrentState_; }


	/**
	 * 현재 공의 상태를 설정합니다.
	 * 
	 * @param InState - 설정할 공의 상태입니다.
	 */
	void SetCurrentState(const EState& InState) { CurrentState_ = InState; }


	/**
	 * 공의 상태를 초기화합니다.
	 */
	void Reset();


	/**
	 * 공을 임의의 방향으로 출발하게 합니다.
	 */
	void Start();


private:
	/**
	 * 공의 현재 상태입니다.
	 */
	EState CurrentState_ = EState::WAIT;
};