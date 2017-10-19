#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject( const sf::Vector2f& size, sf::RenderWindow* window );

	virtual void Draw() = 0;
	virtual void Update( const sf::Time& elapsedTime ) = 0;

	float GetWidth() const;
	float GetHeight() const;

protected:
	sf::RenderWindow* GetRenderWindow() const;

private:
	sf::RenderWindow* window;
	float width;
	float height;
};

