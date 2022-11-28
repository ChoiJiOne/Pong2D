#pragma once

#include <cstddef>

#include <AudioComponent.h>


/**
 * 게임 내에 충돌이 발생했을 때 처리할 사운드 컴포넌트입니다.
 */
class CollisionAudioComponent : public AudioComponent
{
public:
	/**
	 * 게임 내에 충돌이 발생했을 때 처리할 사운드 컴포넌트의 생성자입니다.
	 * 
	 * @param InObject - 이 컴포넌트를 소유하고 있는 게임 오브젝트의 포인터입니다.
	 * @param InAudioKey - 이 컴포넌트가 플레이할 오디오 리소스의 키 값입니다.
	 */
	explicit CollisionAudioComponent(GameObject* InObject, const std::size_t& InAudioKey)
		: AudioComponent(InObject)
	{
		AudioKey_ = InAudioKey;
	}


	/**
	 * 게임 내에 충돌이 발생했을 때 처리할 사운드 컴포넌트 가상 소멸자입니다.
	 */
	virtual ~CollisionAudioComponent() {}


	/**
	 * 게임 내에 충돌이 발생했을 때 처리할 사운드 컴포넌트를 업데이트합니다.
	 */
	virtual void Tick() override;


	/**
	 * 충돌 감지 여부를 설정합니다.
	 * 
	 * @param bIsDetectCollision - 설정할 충돌 감지 여부 값입니다.
	 */
	void SetDetectCollision(bool bIsDetectCollision)
	{
		bIsDetectCollision_ = bIsDetectCollision;
	}


private:
	/**
	 * 오디오 리소스의 키 값입니다.
	 */
	std::size_t AudioKey_ = 0;


	/**
	 * 충돌이 감지되었는지 확인합니다.
	 */
	bool bIsDetectCollision_ = false;
};
