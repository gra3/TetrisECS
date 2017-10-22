#pragma once

#include <memory>

#include "SFML\Graphics.hpp"

#include "GameObject.h"

class TetrisGame
{
public:
	TetrisGame();

	void Start();

	void CreateTetrisBoard( );
	void CreateBlocks( );
	sf::Vector2f GetStartingPosition() const;

private:
	enum Zorder
	{
		Bottom,
		Top
	};

	const int boardWidthInBlocks = 10;
	const int boardHeightInBlocks = 20;

	sf::Vector2f boardStartingPosition;
	sf::Vector2i boardSize;

	std::unique_ptr < sf::RenderWindow > renderWindow;

	std::vector< std::vector< std::unique_ptr< GameObject > > > gameObjects;
};

