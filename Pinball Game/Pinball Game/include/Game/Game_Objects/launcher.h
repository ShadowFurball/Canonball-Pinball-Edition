#pragma once
#ifndef _LAUNCHER_H
#define _LAUNCHER_H

#include<SFML\Graphics.hpp>
#include<Graphics\rectangle.h>

class Launcher : public Rectangle, public sf::Drawable
{
public:
	Launcher();
	Launcher(float width, float height, math::Vector2D pos, float rotation);

	void updateMovable(float time);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
	sf::RectangleShape drawObject;
};
#endif // !_LAUNCHER_H