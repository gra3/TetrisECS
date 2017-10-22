#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "Block.h"
#include "BoardGraphicsComponent.h"
#include "GameObject.h"
#include "PositionComponent.h"
#include "Tetrimino.h"

class TetrisBoard :
	public GameObject
{
public:
	TetrisBoard( sf::RenderWindow* window );

	//GameObject contract
	virtual void Update( const sf::Time& elapsedTime ) override;
};

