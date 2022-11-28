#pragma once

#include <cstddef>

#include <AudioComponent.h>


/**
 * ���� ���� �浹�� �߻����� �� ó���� ���� ������Ʈ�Դϴ�.
 */
class CollisionAudioComponent : public AudioComponent
{
public:
	/**
	 * ���� ���� �浹�� �߻����� �� ó���� ���� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param InObject - �� ������Ʈ�� �����ϰ� �ִ� ���� ������Ʈ�� �������Դϴ�.
	 * @param InAudioKey - �� ������Ʈ�� �÷����� ����� ���ҽ��� Ű ���Դϴ�.
	 */
	explicit CollisionAudioComponent(GameObject* InObject, const std::size_t& InAudioKey)
		: AudioComponent(InObject)
	{
		AudioKey_ = InAudioKey;
	}


	/**
	 * ���� ���� �浹�� �߻����� �� ó���� ���� ������Ʈ ���� �Ҹ����Դϴ�.
	 */
	virtual ~CollisionAudioComponent() {}


	/**
	 * ���� ���� �浹�� �߻����� �� ó���� ���� ������Ʈ�� ������Ʈ�մϴ�.
	 */
	virtual void Tick() override;


	/**
	 * �浹 ���� ���θ� �����մϴ�.
	 * 
	 * @param bIsDetectCollision - ������ �浹 ���� ���� ���Դϴ�.
	 */
	void SetDetectCollision(bool bIsDetectCollision)
	{
		bIsDetectCollision_ = bIsDetectCollision;
	}


private:
	/**
	 * ����� ���ҽ��� Ű ���Դϴ�.
	 */
	std::size_t AudioKey_ = 0;


	/**
	 * �浹�� �����Ǿ����� Ȯ���մϴ�.
	 */
	bool bIsDetectCollision_ = false;
};
