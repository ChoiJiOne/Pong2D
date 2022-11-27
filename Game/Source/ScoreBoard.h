#pragma once

#include <Color.h>
#include <GameObject.h>


/**
 * Pong2D 게임의 플레이어들이 확득한 점수를 나타내는 스코어 보드입니다.
 */
class ScoreBoard : public GameObject
{
public:
	/**
	 * Pong2D 게임의 스코어 보드 생성자입니다.
	 * 
	 * @param InWorld - 게임 스코어 보드가 위치할 월드입니다.
	 * @param InSignature - 게임 스코어 보드의 시그니처 해쉬 값입니다.
	 * @param InPosition - 게임 스코어 보드의 위치입니다.
	 * @param InWidth - 게임 스코어 보드의 가로 크기입니다.
	 * @param InHeight - 게임 스코어 보드의 세로 크기입니다.
	 * @param InColor - 게임 스코어 보드의 색상입니다.
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
	 * Pong2D 게임의 스코어 보드 가상 소멸자입니다.
	 */
	virtual ~ScoreBoard();


	/**
	 * 게임 스코어 보드의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(ScoreBoard);


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
	 * 스코어 보드를 초기화합니다.
	 */
	void Reset() { Player1Score_ = 0, Player2Score_ = 0; }


	/**
	 * 플레이어1의 점수를 얻습니다.
	 * 
	 * @return 플레이어1의 점수를 반환합니다.
	 */
	int32_t GetPlayer1Score() const { return Player1Score_; }


	/**
	 * 플레이어2의 점수를 얻습니다.
	 * 
	 * @return 플레이어2의 점수를 반환합니다.
	 */
	int32_t GetPlayer2Score() const { return Player2Score_; }


private:
	/**
	 * 플레이어1의 점수입니다.
	 */
	int32_t Player1Score_ = 0;


	/**
	 * 플레이어2의 점수입니다.
	 */
	int32_t Player2Score_ = 0;
};