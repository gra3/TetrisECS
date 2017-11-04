#pragma once

#include "GameObject.h"
#include "TetriminoColors.h"

#include <SFML/Graphics.hpp>

class Tetrimino :
	public GameObject
{
public:
	Tetrimino();

	void CreateBlockContainer();
	void AddBlock( const sf::Vector2f& size, const sf::Vector2i& boardPosition, TetriminoColors color );

private:
	sf::Time timeToUpdate;
	sf::Time totalElapsedTime;
};

