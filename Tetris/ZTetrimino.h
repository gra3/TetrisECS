#pragma once

#include "Tetrimino.h"

class ZTetrimino :
	public Tetrimino
{
public:
	ZTetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size );

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

