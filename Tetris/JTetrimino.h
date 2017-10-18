#pragma once

#include "Tetrimino.h"

class JTetrimino :
	public Tetrimino
{
public:
	JTetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window );

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

