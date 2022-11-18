#pragma once

#include "Misc/Vector.h"
#include "Misc/MacroUtils.h"

#include <unordered_map>
#include <memory>

class World;
class Input;
class Camera;
class Renderer;
class Component;


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
	 * @param InInput - 게임의 입력 처리를 위한 입력입니다.
	 * @param InDeltaTime - 초단위 델타 시값값 입니다.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) = 0;


	/**
	 * 게임 오브젝트를 화면에 그립니다.
	 * 
	 * @param InGraphics - 게임의 렌더링 처리를 위한 렌더러입니다.
	 * @param InCamera - 게임의 시야 처리를 위한 카메라입니다.
	 */
	virtual void Render(Renderer& InRenderer, Camera& InCamera) = 0;


	/**
	 * 게임 오브젝트에 컴포넌트를 추가합니다.
	 * 이때, 키 값에 대응하는 컴포넌트가 존재한다면 아무런 동작도 수행하지 않습니다.
	 * 
	 * @param InKey - 추가할 컴포넌트의 키값입니다.
	 */
	template<typename T>
	void AddComponent(const std::size_t& InKey)
	{
		if (HaveComponent(InKey)) return;

		std::unique_ptr<T> NewComponent = std::make_unique<T>(this);
		Components_.insert({ InKey, std::move(NewComponent) });
	}


	/**
	 * 게임 오브젝트가 소유하고 있는 컴포넌트를 얻습니다.
	 * 
	 * @param InKey - 게임 오브젝트가 소유하고 있는 컴포넌트의 키 값입니다.
	 * 
	 * @return 키 값에 대응하는 컴포넌트가 존재하면 주소 값을 반환, 그렇지 않으면 nullptr를 반환합니다.
	 */
	template<typename T>
	T* GetComponent(const std::size_t& InKey)
	{
		if (!HaveComponent(InKey)) return nullptr;

		return reinterpret_cast<T*>(Components_.at(InKey).get());
	}


	/**
	 * 게임 오브젝트가 소유하고 있는 컴포넌트를 삭제합니다.
	 * 이때, 키 값에 대응하는 컴포넌트가 존재하지 않는다면, 아무런 동작도 하지 않습니다.
	 * 
	 * @param InKey - 게임 오브젝트가 소유하고 있는 컴포넌트의 키 값입니다.
	 */
	template<typename T>
	void RemoveComponent(const std::size_t& InKey)
	{
		if (!HaveComponent(InKey)) return;

		Components_.erase(InKey);
	}


private:
	/**
	 * 키 값에 대응하는 컴포넌트가 존재하는지 검사합니다.
	 * 
	 * @param InKey - 검사를 수행Header할 키 값입니다.
	 * 
	 * @return 키 값에 대응하는 컴포넌트가 존재하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool HaveComponent(const std::size_t& InKey);


protected:
	/**
	 * 게임 오브젝트가 위치한 월드입니다.
	 */
	World* World_ = nullptr;


	/**
	 * 게임 오브젝트가 소유하고 있는 컴포넌트입니다.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Component>> Components_;
};