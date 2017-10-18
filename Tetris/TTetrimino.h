#pragma once

#include "Tetrimino.h"

class TTetrimino :
	public Tetrimino
{
public:
	TTetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window );

	//TetriminoContract
	virtual void InitTetrimino() override;
};

