#include "CollisionAudioComponent.h"

#include <ContentManager.h>
#include <Sound.h>

void CollisionAudioComponent::Tick()
{
	if (bIsDetectCollision_)
	{
		ContentManager::Get().GetSound(AudioKey_).Play();
		bIsDetectCollision_ = false;
	}
}
