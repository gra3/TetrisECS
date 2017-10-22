#pragma once

#include "SFML\Graphics.hpp"

#include "GraphicsComponent.h"

class TetrisBoard;

class BoardGraphicsComponent:
	public GraphicsComponent
{
public:
	BoardGraphicsComponent( const sf::Vector2i size, int widthInBlocks, int heightInBlocks );

private:
	const float borderThickness = 5;

	sf::Vector2i boardSize;
	int widthInBlocks;
	int heightInBlocks;

	void DrawBorder( sf::RenderTexture* renderTexture ) const;
	void DrawGrid( sf::RenderTexture* renderTexture ) const;

	//GraphicsComponent contract
	virtual void LoadSprite() override;
};