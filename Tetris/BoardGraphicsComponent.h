#pragma once

#include "SFML\Graphics.hpp"

#include "GraphicsComponent.h"

class TetrisBoard;

class BoardGraphicsComponent:
	public GraphicsComponent
{
public:
	BoardGraphicsComponent( const sf::Vector2i size, const sf::Vector2i& boardSizeInBlocks, int borderThickness );

private:
	float borderThickness = 5;
	sf::Vector2i boardSize;
	sf::Vector2i boardSizeInBlocks;

	void DrawBorder( sf::RenderTexture* renderTexture ) const;
	void DrawGrid( sf::RenderTexture* renderTexture ) const;

	//GraphicsComponent contract
	virtual void LoadSprite() override;
};