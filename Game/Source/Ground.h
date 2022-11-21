#pragma once

#include <GameObject.h>


/**
 * Pong2D 게임 그라운드 클래스입니다.
 */
class Ground : public GameObject
{
public:
	/**
	 * 그라운드의 Normal 벡터의 타입입니다.
	 */
	enum class ENormal
	{
		NONE   = 0,
		TOP    = 1,
		BOTTOM = 2,
		LEFT   = 3,
		RIGHT  = 4
	};


public:
	/**
	 * Pong2D 게임 그라운드의 생성자입니다.
	 *
	 * @param InWorld - 게임 그라운드가 위치할 월드입니다.
	 * @param InSignature - 게임 그라운드의 시그니처 해쉬 값입니다.
	 * @param InPosition - 게임 그라운드의 화면상 위치입니다.
	 * @param InWidth - 게임 그라운드의 가로 크기입니다.
	 * @param InHeight - 게임 그라운드의 세로 크기입니다.
	 */
	explicit Ground(
		World* InWorld,
		const std::size_t& InSignature,
		const Vec2f& InPosition,
		const float& InWidth,
		const float& InHeight
	);


	/**
	 * Pong2D 게임 그라운드의 가상 소멸자입니다.
	 */
	virtual ~Ground();


	/**
	 * 게임 그라운드의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Ground);


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
	 * @param InGraphics - 게임의 렌더링 처리를 위한 렌더러입니다.
	 * @param InCamera - 게임의 시야 처리를 위한 카메라입니다.
	 */
	virtual void Render(Renderer& InRenderer, Camera& InCamera) override;


	/**
	 * 게임 그라운드의 Normal 벡터를 얻습니다.
	 * 
	 * @parma InType - 그라운드 Normal 벡터의 타입입니다.
	 * 
	 * @return 타입에 대응하는 Normal 벡터를 반환합니다.
	 */
	Vec2f GetNormal(const ENormal& InType) const;


private:
	/**
	 * ENormal에 대응하는 Normal 벡터입니다.
	 */
	std::unordered_map<ENormal, Vec2f> Normals_;
};