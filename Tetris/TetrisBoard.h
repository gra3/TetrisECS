#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "Block.h"
#include "GameObject.h"
#include "Tetrimino.h"

class TetrisBoard :
	public GameObject
{
public:
	TetrisBoard( const sf::Vector2f& size, sf::RenderWindow* window );

	void InitBlockArray();

	//GameObject contract
	virtual void Draw() override;
	virtual void Update( const sf::Time& elapsedTime ) override;

private:
	const int boardWidthInBlocks = 10;
	const int boardHeightInBlocks = 20;
	const float borderThickness = 5;
	std::vector< std::vector< Block > > blockArray;

	void DrawBorder();
	void DrawGrid();
	void DrawBlocks();

	float GetBlockWidth();
	float GetBlockHeight();

	BoardPositionComponent GetStartingTetriminoBoardPosition() const;

};

