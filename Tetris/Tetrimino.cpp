#include "Tetrimino.h"

Tetrimino::Tetrimino() 
{
}

void Tetrimino::Update( const sf::Time& elapsedTime )
{
	totalElapsedTime += elapsedTime;
	if ( totalElapsedTime >= timeToUpdate )
	{

		totalElapsedTime -= timeToUpdate;
	}
	
}