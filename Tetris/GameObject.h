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

	UINT GetComponentMask() const;
	void AddComponent( std::unique_ptr< Component > component );
	Component* GetComponent( ComponentID componentID ) const;
	void RemoveComponent( ComponentID componentID );

	void Activate();
	void Deactivate();
	bool IsActive() const;

private:
	UINT componentMask;
	std::vector < std::unique_ptr< Component > > components;

	bool isActive;
};

