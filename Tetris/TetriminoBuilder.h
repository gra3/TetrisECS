#pragma once

#include <memory>

#include "SFML\System.hpp"

class Tetrimino;

class TetriminoBuilder
{
public:
	enum TetriminoType
	{
		ITetrimino,
		JTetrimino,
		LTetrimino,
		OTetrimino,
		STetrimino,
		TTetrimino,
		ZTetrimino
	};

	TetriminoBuilder( const sf::Vector2i& startingPosition, const sf::Vector2f& tetriminoSize );
	std::unique_ptr< Tetrimino > BuildTetrimino( TetriminoType type ) const;

private:
	sf::Vector2f size;
	sf::Vector2i startingPosition;

	sf::Vector2i GetBoardPosition( int x, int y ) const;
};

