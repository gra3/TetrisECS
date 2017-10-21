#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "Block.h"
#include "BoardGraphicsComponent.h"
#include "GameObject.h"
#include "PositionComponent.h"
#include "Tetrimino.h"

class TetrisBoard :
	public GameObject
{
public:
	TetrisBoard( const sf::Vector2f& size, sf::RenderWindow* window );

	void InitBlockArray();

	//GameObject contract
	virtual void Update( const sf::Time& elapsedTime ) override;

	float GetBlockWidth() const;
	float GetBlockHeight() const;

	int GetBoardWidthInBlocks() const;
	int GetBoardHeightInBlocks() const;

	PositionComponent* GetPositionComponent() { return &positionComponent; };
	BoardGraphicsComponent* GetGraphicsComponent() { return &boardGraphicsComponent; };

private:
	const int boardWidthInBlocks = 10;
	const int boardHeightInBlocks = 20;
	const float borderThickness = 5;

	std::vector< std::vector< Block > > blockArray;

	PositionComponent positionComponent;
	BoardGraphicsComponent boardGraphicsComponent;

	BoardPositionComponent GetStartingTetriminoBoardPosition() const;
};

