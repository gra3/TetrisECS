#pragma once

#include "SFML\Graphics.hpp"

#include "GraphicsComponent.h"

class TetrisBoard;

class BoardGraphicsComponent:
	public GraphicsComponent
{
public:
	BoardGraphicsComponent( TetrisBoard* board );

private:
	const float borderThickness = 5;

	TetrisBoard* tetrisBoard;

	virtual void LoadSprite();
	void DrawBorder( sf::RenderTexture* renderTexture ) const;
	void DrawGrid( sf::RenderTexture* renderTexture ) const;
};