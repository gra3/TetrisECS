#include "Tetrimino.h"

Tetrimino::Tetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window ) :
	GameObject{ rect, window },
	timeToUpdate{ sf::seconds( 1.0 ) },
	totalElapsedTime{ sf::Time::Zero }
{
	tetriminoArray.resize( widthInBlocks );
	for( int i = 0; i < widthInBlocks; i++ )
		for ( int j = 0; j < heightInBlocks; j++ )
		{
			auto width = GetWidth() / widthInBlocks;
			auto height = GetHeight() / heightInBlocks;
			auto x = GetX() + width * i;
			auto y = GetY() + height * j;
			sf::Rect< float > blockRect( x, y, width, height );
			tetriminoArray[ i ].emplace_back( blockRect, GetRenderWindow() );
		}
}

void Tetrimino::Draw()
{
	for ( auto& vec : tetriminoArray )
		for ( auto& block : vec )
			block.Draw();
}

void Tetrimino::Update( const sf::Time& elapsedTime )
{
	totalElapsedTime += elapsedTime;
	if ( totalElapsedTime >= timeToUpdate )
	{
		auto currentY = GetY();
		SetY( currentY + GetHeight() );
		for( auto& vec : tetriminoArray )
			for ( auto& block : vec )
			{
				auto currentY = block.GetY();
				block.SetY( currentY + block.GetHeight() );
			}

		totalElapsedTime -= timeToUpdate;
	}
	
}

void Tetrimino::ActivateBlock( int x, int y, TetriminoColors color )
{
	tetriminoArray[ x ][ y ].Activate();
	tetriminoArray[ x ][ y ].SetColor( color );
}
