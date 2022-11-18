#include "Core/World.h"
#include "Core/GameObject.h"

World::~World()
{
}

void World::AddOjbect(GameObject* InObject)
{
	if (IsExistObject(InObject)) return;

	GameObjects_.push_back(InObject);
}

bool World::IsExistObject(GameObject* InObject)
{
	for (const auto& Object : GameObjects_)
	{
		if (Object == InObject)
		{
			return true;
		}
	}

	return false;
}

void World::RemoveObject(GameObject* InObject)
{
	if (!IsExistObject(InObject)) return;

	GameObjects_.remove(InObject);
}
