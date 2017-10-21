#pragma once

#include "BoardPositionComponent.h"
#include "GameObject.h"
#include "TetriminoColors.h"

class Block :
	public GameObject
{
public:
	Block( const BoardPositionComponent& initialBoardPosition, const sf::Vector2f size );

	void SetColor( TetriminoColors color );
	void Activate();
	void Deactivate();

	//GameObject contract
	virtual void Update( const sf::Time& elapsedTime ) override;

private:
	BoardPositionComponent boardPosition;
	bool active;
	TetriminoColors color;

	sf::Color GetBlockColor() const;
};

