#pragma once

#include "GameObject.h"


/**
 * Pong2D 게임 플레이어 클래스입니다.
 */
class Player : public GameObject
{
public:
	/**
	 * Pong2D 게임 플레이어의 생성자입니다.
	 * 
	 * @param InWorld - 게임 플레이어가 위치할 월드입니다.
	 */
	explicit Player(World* InWorld);


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
	 * @param InInput - 게임의 입력 처리 인스턴스입니다.
	 * @param InDeltaTime - 초단위 델타 시값값 입니다.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * 게임 플레이어를 화면에 그립니다.
	 *
	 * @param InGraphics - 게임의 렌더링 처리 인스턴스입니다.
	 */
	virtual void Render(Graphics& InGraphics) override;
};