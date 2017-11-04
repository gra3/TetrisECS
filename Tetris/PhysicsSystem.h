#pragma once

#include <memory>
#include <vector>

#include "GameObject.h"

class PhysicsSystem
{
public:
	PhysicsSystem();

	void DoPhysics( std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects, const sf::Time& elapsedTime );

	void HandlePhysics( const GameObject* obj, const sf::Time& elapsedTime );
	void HandlePhysicsForAllContainedObjects( const GameObject* obj, const sf::Time& elapsedTime );

private:
	bool HasPositionAndVelocityComponents( const GameObject* object );
	bool HasContainerComponent( const GameObject* object ) const;
};

