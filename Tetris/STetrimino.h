#pragma once

#include "Tetrimino.h"

class STetrimino :
	public Tetrimino
{
public:
	STetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window );

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

