#include "Tetrimino.h"

Tetrimino::Tetrimino( const BoardPositionComponent& initialBoardPosition, const sf::Vector2f& size ):
	GameObject{},
	boardPosition{ initialBoardPosition },
	timeToUpdate{ sf::seconds( 1.0 ) },
	totalElapsedTime{ sf::Time::Zero }
{
	//tetriminoArray.resize( widthInBlocks );
	//for( int i = 0; i < widthInBlocks; i++ )
	//	for ( int j = 0; j < heightInBlocks; j++ )
	//	{
	//		auto x = boardPosition.GetX() + i;
	//		auto y = boardPosition.GetY() + j;
	//		BoardPositionComponent blockBoardPosition( sf::Vector2i( x, y ) );
	//		sf::Vector2f size(  GetWidth() / 4, GetHeight() / 4 );
	//		tetriminoArray[ i ].emplace_back( blockBoardPosition, size );
	//	}
}

void Tetrimino::Update( const sf::Time& elapsedTime )
{
	totalElapsedTime += elapsedTime;
	if ( totalElapsedTime >= timeToUpdate )
	{
		//auto currentY = GetY();
		//SetY( currentY + GetHeight() );
		//for( auto& vec : tetriminoArray )
		//	for ( auto& block : vec )
		//	{
		//		auto currentY = block.GetY();
		//		block.SetY( currentY + block.GetHeight() );
		//	}

		totalElapsedTime -= timeToUpdate;
	}
	
}

void Tetrimino::ActivateBlock( int x, int y, TetriminoColors color )
{
	tetriminoArray[ x ][ y ].Activate();
	//tetriminoArray[ x ][ y ].SetColor( color );
}
