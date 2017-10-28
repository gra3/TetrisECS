#pragma once
#include <memory>

#include "SFML\Graphics.hpp"

#include "GameObject.h"

class TetrisGame;

class RenderSystem
{
public:
	RenderSystem( TetrisGame* tetrisGame, sf::RenderWindow* renderWindow );

	void Render( std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects );

private:
	sf::RenderWindow* renderWindow;
	TetrisGame* tetrisGame;

	bool HasPositionAndGraphicsComponent( GameObject* object ) const;
	bool HasContainerComponent( GameObject* object ) const;

	void DrawGameObject( GameObject* obj );

	void DrawAllContainedGameObjects( GameObject* obj );
};

