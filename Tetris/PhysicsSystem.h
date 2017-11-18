#pragma once

#include <memory>
#include <vector>

#include "CollisionSystem.h"
#include "GameObject.h"

class TetrisGame;

class PhysicsSystem
{
public:
	PhysicsSystem( TetrisGame* game );

	void DoPhysics( std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects, const sf::Time& elapsedTime );

	void HandlePhysics( const GameObject* obj, const sf::Time& elapsedTime, std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects );
	void HandlePhysicsForAllContainedObjects( const GameObject* obj, const sf::Time& elapsedTime, std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects );

private:
	TetrisGame* tetrisGame;
	CollisionSystem collisionSystem;
	bool stop;

	bool HasPositionAndVelocityComponents( const GameObject* object );
	bool HasContainerComponent( const GameObject* object ) const;
};

