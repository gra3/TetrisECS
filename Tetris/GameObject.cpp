#include "GameObject.h"

GameObject::GameObject() :
	componentMask{ 0 },
	isActive{ true }
{
}

UINT GameObject::GetComponentMask() const
{
	return componentMask;
}

void GameObject::AddComponent( std::unique_ptr< Component > component )
{
	UINT componentID = component->GetComponentID();
	componentMask = componentMask | componentID;
	components.emplace_back( std::move( component ) );
}

Component* GameObject::GetComponent( ComponentID componentID ) const
{
	Component* desiredComponent = nullptr;

	for ( auto& component : components )
	{
		if ( component->GetComponentID() == componentID )
			desiredComponent = component.get();
	}

	return desiredComponent;
}

void GameObject::RemoveComponent( ComponentID componentID )
{
	for ( auto it = components.begin(); it != components.end(); it++ )
	{
		if ( ( *it )->GetComponentID() == componentID )
		{
			components.erase( it );
			componentMask -= componentID;
			return;
		}
	}
}

void GameObject::Activate()
{
	isActive = true;
}

void GameObject::Deactivate()
{
	isActive = false;
}

bool GameObject::IsActive() const
{
	return isActive;
}
