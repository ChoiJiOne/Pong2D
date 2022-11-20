#pragma once

#include <GameObject.h>


/**
 * Pong2D 게임 플레이어입니다.
 */
class Player : public GameObject
{
public:
	/**
	 * 플레이어 타입입니다.
	 * PLAYER1는 왼쪽 플레이어이고, PLAYER2는 오른쪽 플레이어입니다.
	 */
	enum class EType : int32_t
	{
		PLAYER1 = 0,
		PLAYER2 = 1,
	};


public:
	/**
	 * Pong2D 게임 플레이어의 생성자입니다.
	 *
	 * @param InWorld - 게임 플레이어가 위치할 월드입니다.
	 * @param InSignature - 게임 플레이어의 시그니처 해쉬 값입니다.
	 * @param InType - 게임 플레이어의 타입입니다.
	 * @param InPosition - 게임 플레이어의 화면상 위치입니다.
	 * @param InWidth - 게임 플레이어의 가로 크기입니다.
	 * @param InHeight - 게임 플레이어의 세로 크기입니다.
	 * @param InVelocity - 게임 플레이어의 속도입니다.
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
	 * Pong2D 게임 플레이어의 가상 소멸자입니다.
	 */
	virtual ~Player();


	/**
	 * 게임 플레이어의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Player);


	/**
	 * 게임 플레이어를 업데이트합니다.
	 *
	 * @param InInput - 게임의 입력 처리를 위한 입력입니다.
	 * @param InDeltaTime - 초단위 델타 시값값 입니다.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * 게임 플레이어를 화면에 그립니다.
	 *
	 * @param InGraphics - 게임의 렌더링 처리를 위한 렌더러입니다.
	 * @param InCamera - 게임의 시야 처리를 위한 카메라입니다.
	 */
	virtual void Render(Renderer& InRenderer, Camera& InCamera) override;


	/**
	 * 플레이어의 타입을 얻습니다.
	 *
	 * @return 플레이어의 타입을 반환합니다.
	 */
	EType GetType() const { return Type_; }


private:
	/**
	 * 게임 플레이어의 타입입니다.
	 */
	EType Type_;
};