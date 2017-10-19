#include "JTetrimino.h"

JTetrimino::JTetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size, sf::RenderWindow* window ):
	Tetrimino( boardPosition, size, window )
{
	InitTetrimino();
}

void JTetrimino::InitTetrimino()
{
	ActivateBlock( 0, 0, Blue );
	ActivateBlock( 0, 1, Blue );
	ActivateBlock( 1, 1, Blue );
	ActivateBlock( 2, 1, Blue );
}
