#include "GameObject.h"
#include "RigidBody.h"
#include "InputComponent.h"
#include "GraphicsComponent.h"
#include "PhysicComponent.h"
#include "AudioComponent.h"
#include "World.h"

GameObject::GameObject(World* InWorld)
{
	World_ = InWorld;
	World_->AddOjbect(this);
}

GameObject::~GameObject()
{
	for (auto& component : Components_)
	{
		component.second.reset();
	}

	World_->RemoveObject(this);
}

bool GameObject::HaveComponent(const std::size_t& InKey)
{
	return Components_.find(InKey) != Components_.end();
}
