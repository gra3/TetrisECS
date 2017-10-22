#pragma once

#include <memory>
#include <vector>
#include <wtypes.h>

#include <SFML/Graphics.hpp>

#include "Component.h"

class GameObject
{
public:
	GameObject();

	virtual void Update( const sf::Time& elapsedTime ) = 0;

	UINT GetComponentMask() const;
	void AddComponent( std::unique_ptr< Component > component );
	Component* GetComponent( ComponentID componentID ) const;

private:
	UINT componentMask;
	std::vector < std::unique_ptr< Component > > components;
};

