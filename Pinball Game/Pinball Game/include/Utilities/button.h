#pragma once

#ifndef _BUTTON_H
#define _BUTTON_H

#include <Graphics\rectangle.h>
#include <SFML\Graphics.hpp>
class Button : public Rectangle, sf::Drawable
{
	public:
		Button();
		Button(sf::Image*, sf::Image*, int, int, math::Vector2D);
	private:
};
#endif // !_BUTTON_H

