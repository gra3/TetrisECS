#pragma once

#include <SFML/Graphics.hpp>

#include "Block.h"
#include "BoardPositionComponent.h"
#include "GameObject.h"

class Tetrimino :
	public GameObject
{
public:
	Tetrimino();

	//GameObject contract
	virtual void Update( const sf::Time& elapsedTime ) override;

protected:
	std::vector< std::vector< Block > > tetriminoArray;
	virtual void InitTetrimino() = 0;

private:
	sf::Time timeToUpdate;
	sf::Time totalElapsedTime;
};

