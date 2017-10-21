#pragma once

#include <memory>
#include <vector>
#include <wtypes.h>

#include <SFML/Graphics.hpp>

#include "Component.h"

class GameObject
{
public:
	GameObject( const sf::Vector2f& size );

	virtual void Update( const sf::Time& elapsedTime ) = 0;

	UINT GetComponentMask() const;
	void AddComponent( std::unique_ptr< Component > component );
	Component* GetComponent( ComponentID componentID ) const;

	float GetWidth() const;
	float GetHeight() const;

private:
	UINT componentMask;
	std::vector < std::unique_ptr< Component > > components;

	float width;
	float height;
};

