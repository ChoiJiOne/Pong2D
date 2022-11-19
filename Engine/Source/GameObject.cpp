#include <GameObject.h>
#include <World.h>
#include <Component.h>

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