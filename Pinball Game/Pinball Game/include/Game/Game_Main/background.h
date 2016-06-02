#pragma once
#ifndef _BACKGROUND_H
#define _BACKGROUND_H

#include<SFML\Graphics.hpp>
#include<Graphics\rectangle.h>

class Background : public Rectangle, public sf::Drawable
{
public:
	Background();
	Background(float width, float height, math::Vector2D pos, float rotation);

	void updateMovable(float time);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
	sf::RectangleShape drawObject;
};
#endif // !_BACKGROUND_H