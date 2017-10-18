#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject( const sf::Rect< float >& rect, sf::RenderWindow* window );

	virtual void Draw() = 0;
	virtual void Update( const sf::Time& elapsedTime ) = 0;

	float GetX() const;
	void SetX( float x );
	float GetY() const;
	void SetY( float y );
	float GetWidth() const;
	float GetHeight() const;

protected:
	sf::RenderWindow* GetRenderWindow() const;

private:
	sf::RenderWindow* window;
	float x;
	float y;
	float width;
	float height;
};

