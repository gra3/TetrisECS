#pragma once
#include <memory>

#include "SFML\Graphics.hpp"

class TetrisGame
{
public:
	TetrisGame();

	void Start();

private:
	std::unique_ptr < sf::RenderWindow > renderWindow;
};

