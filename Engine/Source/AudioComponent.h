#pragma once

#include <Component.h>


/**
 * 게임 오브젝트의 오디오 처리를 수행하는 컴포넌트입니다.
 */
class AudioComponent : public Component
{
public:
	/**
	 * 오디오 처리를 수행하는 컴포넌트의 생성자입니다.
	 * 
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 */
	explicit AudioComponent(GameObject* InObject) : Component(InObject) { }


	/**
	 * 오디오 처리 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~AudioComponent() {}


	/**
	 * 오디오 처리 컴포넌트의 복사 생성자 및 대입연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(AudioComponent);


	/**
	 * 오디오 처리 컴포넌트를 업데이트합니다.
	 */
	virtual void Tick() = 0;
};