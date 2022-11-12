#pragma once

#include "Vector.h"
#include "Macro.h"

#include <memory>

class World;
class Body;
class Input;
class Graphics;
class InputComponent;
class BodyComponent;
class PhysicComponent;
class GraphicsComponent;
class SoundComponent;


/**
 * 게임 오브젝트 클래스입니다.
 * 게임 내의 오브젝트는 이 클래스를 상속받아야 합니다.
 */
class GameObject
{
public:
	/**
	 * 게임 오브젝트의 생성자입니다.
	 * 
	 * @param InWorld - 게임 오브젝트가 위치할 월드입니다.
	 */
	explicit GameObject(World* InWorld);


	/**
	 * 게임 오브젝트의 가상 소멸자입니다.
	 */
	virtual ~GameObject();

	
	/**
	 * 게임 오브젝트의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(GameObject);


	/**
	 * 게임 오브젝트를 업데이트합니다.
	 *
	 * @param InInput - 게임의 입력 처리 인스턴스입니다.
	 * @param InDeltaTime - 초단위 델타 시값값 입니다.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) = 0;


	/**
	 * 게임 오브젝트를 화면에 그립니다.
	 * 
	 * @param InGraphics - 게임의 렌더링 처리 인스턴스입니다.
	 */
	virtual void Render(Graphics& InGraphics) = 0;


	/**
	 * 게임 오브젝트의 바디를 얻습니다.
	 * 
	 * @return 게임 오브젝트 바디의 변경 불가능한 참조자를 반환합니다.
	 */
	const Body& GetBody() const { return *Body_.get(); }


	/**
	 * 게임 오브젝트의 바디를 얻습니다.
	 * 
	 * @return 게임 오브젝트 바디의 변경 가능한 참조자를 반환합니다.
	 */
	Body& GetBody() { return *Body_.get(); }


protected:
	/**
	 * 게임 오브젝트가 위치한 월드입니다.
	 */
	World* World_ = nullptr;


	/**
	 * 게임 오브젝트의 바디입니다.
	 */
	std::unique_ptr<Body> Body_ = nullptr;


	/**
	 * 게임 오브젝트의 입력 처리 컴포넌트입니다.
	 */
	std::unique_ptr<InputComponent> Input_ = nullptr;


	/**
	 * 게임 오브젝트의 물리 처리 컴포넌트입니다.
	 */
	std::unique_ptr<PhysicComponent> Physic_ = nullptr;


	/**
	 * 게임 오브젝트의 렌더링 처리 컴포넌트입니다.
	 */
	std::unique_ptr<GraphicsComponent> Graphics_ = nullptr;


	/**
	 * 게임 오브젝트의 사운드 처리 컴포넌트입니다.
	 */
	std::unique_ptr<SoundComponent> Sound_ = nullptr;
};