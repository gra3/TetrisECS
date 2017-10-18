#pragma once

#include "Tetrimino.h"

class OTetrimino :
	public Tetrimino
{
public:
	OTetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window );

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

