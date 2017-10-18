#pragma once

#include "Tetrimino.h"

class ZTetrimino :
	public Tetrimino
{
public:
	ZTetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window );

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

