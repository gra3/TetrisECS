#pragma once

#include "GameObject.h"
#include "TetriminoColors.h"

class Block :
	public GameObject
{
public:
	Block( const sf::Rect< float > rect, sf::RenderWindow* window );

	void SetColor( TetriminoColors color );
	void Activate();
	void Deactivate();

	//GameObject contract
	virtual void Draw() override;
	virtual void Update( const sf::Time& elapsedTime ) override;

private:
	bool active;
	TetriminoColors color;

	sf::Color GetBlockColor() const;
};

