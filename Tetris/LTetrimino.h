#pragma once

#include "Tetrimino.h"

class LTetrimino :
	public Tetrimino
{
public:
	LTetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window );

	//TetriminoContract
	virtual void InitTetrimino() override;
};

