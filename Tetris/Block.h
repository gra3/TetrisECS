#pragma once

#include "BoardPositionComponent.h"
#include "GameObject.h"
#include "TetriminoColors.h"

class Block :
	public GameObject
{
public:
	Block();

	//GameObject contract
	virtual void Update( const sf::Time& elapsedTime ) override;
};

