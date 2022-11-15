#pragma once

#include "GameObject.h"


/**
 * Pong2D 게임 그라운드 클래스입니다.
 */
class Ground : public GameObject
{
public:
	/**
	 * Pong2D 게임 그라운드의 생성자입니다.
	 * 
	 * @param InWorld - 게임 그라운드가 위치할 월드입니다.
	 * @param InPosition - 게임 그라운드의 화면상 위치입니다.
	 * @param InWidth - 게임 그라운드의 가로 크기입니다.
	 * @param InHeight - 게임 그라운드의 세로 크기입니다.
	 */
	explicit Ground(
		World* InWorld,
		const Vec2f& InPosition,
		const float& InWidth,
		const float& InHeight
	);


	/**
	 * Pong2D 게임 그라운드의 가상 소멸자입니다.
	 */
	virtual ~Ground();


	/**
	 * 게임 그라운드를 업데이트합니다.
	 *
	 * @param InInput - 게임의 입력 처리 인스턴스입니다.
	 * @param InDeltaTime - 초단위 델타 시값값 입니다.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * 게임 그라운드를 화면에 그립니다.
	 *
	 * @param InGraphics - 게임의 렌더링 처리 인스턴스입니다.
	 */
	virtual void Render(Graphics& InGraphics) override;
};