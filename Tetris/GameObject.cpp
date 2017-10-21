#include "GameObject.h"

GameObject::GameObject( const sf::Vector2f& size ) :
	componentMask{ 0 },
	width{ size.x },
	height{ size.y }
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

float GameObject::GetWidth() const
{
	return width;
}

float GameObject::GetHeight() const
{
	return height;
}