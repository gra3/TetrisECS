#pragma once

#include "Tetrimino.h"

class JTetrimino :
	public Tetrimino
{
public:
	JTetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size, sf::RenderWindow* window );

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

