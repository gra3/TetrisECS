#pragma once

#include "Tetrimino.h"

class ITetrimino :
	public Tetrimino
{
public:
	ITetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size );

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

