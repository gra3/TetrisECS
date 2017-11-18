#pragma once

#include <vector>
#include <memory>

#include "GameObject.h"

class TetrisGame;

class CollisionSystem

{
public:
	CollisionSystem( TetrisGame* game );

	bool DetectCollision( const GameObject* objectInQuestion, std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects ) const;

	bool DoObjectsCollide( const GameObject* objectOne, const GameObject* objectTwo ) const;

	sf::FloatRect GetObjectRect( const GameObject* object ) const;
	bool IsInclusive( const GameObject* object ) const;

	bool HasBodyAndPositionComponents( const GameObject* gameObject ) const;

private:
	TetrisGame* tetrisGame;
};

