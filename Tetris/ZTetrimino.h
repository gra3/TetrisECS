#pragma once

#include "Tetrimino.h"

class ZTetrimino :
	public Tetrimino
{
public:
	ZTetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size, sf::RenderWindow* window );

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

