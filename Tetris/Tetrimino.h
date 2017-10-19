#pragma once

#include <SFML/Graphics.hpp>

#include "Block.h"
#include "BoardPositionComponent.h"
#include "GameObject.h"

class Tetrimino :
	public GameObject
{
public:
	Tetrimino( const BoardPositionComponent& initialBoardPosition, const sf::Vector2f& size, sf::RenderWindow* window );

	//GameObject contract
	virtual void Draw() override;
	virtual void Update( const sf::Time& elapsedTime ) override;

protected:
	std::vector< std::vector< Block > > tetriminoArray;
	virtual void InitTetrimino() = 0;
	void ActivateBlock( int x, int y, TetriminoColors color );

private:
	const int widthInBlocks = 4;
	const int heightInBlocks = 4;

	BoardPositionComponent boardPosition;

	sf::Time timeToUpdate;
	sf::Time totalElapsedTime;
};

