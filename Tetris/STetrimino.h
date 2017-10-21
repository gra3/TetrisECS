#pragma once

#include "Tetrimino.h"

class STetrimino :
	public Tetrimino
{
public:
	STetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size );

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

