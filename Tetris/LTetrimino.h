#pragma once

#include "Tetrimino.h"

class LTetrimino :
	public Tetrimino
{
public:
	LTetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size );

	//TetriminoContract
	virtual void InitTetrimino() override;
};

