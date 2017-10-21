#pragma once

#include "Tetrimino.h"

class OTetrimino :
	public Tetrimino
{
public:
	OTetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size );

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

