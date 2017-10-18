#pragma once

#include "Tetrimino.h"

class ITetrimino :
	public Tetrimino
{
public:
	ITetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window );

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

