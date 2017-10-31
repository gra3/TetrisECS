#pragma once

#include <memory>

#include "SFML\Graphics.hpp"

#include "GameObject.h"

class TetrisGame
{
public:
	TetrisGame();

	void Start();

	void CreateTetrisBoard();
	void CreateTetrimino();

	sf::Vector2f GetStartingPosition() const;
	int GetBorderThickness() const;

private:
	enum Zorder
	{
		Bottom,
		Top
	};

	const int borderThickness = 5;
	const int boardWidthInBlocks = 10;
	const int boardHeightInBlocks = 20;

	sf::Vector2i boardSize;
	sf::Vector2f boardStartingPosition;
	sf::Vector2i tetriminoStartingPosition;

	std::unique_ptr < sf::RenderWindow > renderWindow;

	std::vector< std::vector< std::unique_ptr< GameObject > > > gameObjects;

	sf::Vector2f GetBlockSize() const;
	sf::Vector2i GetBoardSizeInBlocks() const;
};

