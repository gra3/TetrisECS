#include "ITetrimino.h"

ITetrimino::ITetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window ):
	Tetrimino( rect, window )
{
	InitTetrimino();
}

void ITetrimino::InitTetrimino()
{
	ActivateBlock( 0, 0, LightBlue );
	ActivateBlock( 1, 0, LightBlue );
	ActivateBlock( 2, 0, LightBlue );
	ActivateBlock( 3, 0, LightBlue );
}
