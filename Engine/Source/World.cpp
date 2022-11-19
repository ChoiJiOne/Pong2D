#include "World.h"
#include "GameObject.h"

World::~World()
{
}

void World::AddOjbect(GameObject* InObject, const std::size_t& InKey)
{
	if (IsExistObject(InKey)) return;

	GameObjects_.insert({ InKey, InObject });
}

bool World::IsExistObject(const std::size_t& InKey)
{
	return GameObjects_.find(InKey) != GameObjects_.end();
}

void World::RemoveObject(const std::size_t& InKey)
{
	if (!IsExistObject(InKey)) return;

	GameObjects_.erase(InKey);
}
