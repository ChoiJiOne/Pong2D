#include "Core/GameObject.h"
#include "Core/World.h"
#include "Core/Component.h"

GameObject::GameObject(World* InWorld, const std::size_t& InSignature)
{
	World_ = InWorld;
	Signature_ = InSignature;

	World_->AddOjbect(this, Signature_);
}

GameObject::~GameObject()
{
	for (auto& component : Components_)
	{
		component.second.reset();
	}

	World_->RemoveObject(Signature_);
}