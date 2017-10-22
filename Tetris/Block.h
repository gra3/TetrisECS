#pragma once

#include "BoardPositionComponent.h"
#include "GameObject.h"
#include "TetriminoColors.h"

class Block :
	public GameObject
{
public:
	Block();

	void SetColor( TetriminoColors color );
	void Activate();
	void Deactivate();

	//GameObject contract
	virtual void Update( const sf::Time& elapsedTime ) override;

private:
	bool active;
	TetriminoColors color;
};

