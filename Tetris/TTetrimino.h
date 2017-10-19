#pragma once

#include "Tetrimino.h"

class TTetrimino :
	public Tetrimino
{
public:
	TTetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size, sf::RenderWindow* window );

	//TetriminoContract
	virtual void InitTetrimino() override;
};

