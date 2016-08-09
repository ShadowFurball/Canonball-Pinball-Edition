#pragma once

#ifndef _BUTTON_H
#define _BUTTON_H

#include <Graphics\rectangle.h>
#include <SFML\Graphics.hpp>

class Button : public Rectangle, sf::Drawable
{
	enum ButtonState {DEFAULT, HOVERED, CLICKED};

	public:
		Button();
		Button(int, int, math::Vector2D);
		~Button();

		void updateImage(ButtonState);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		sf::RectangleShape m_ButtonShape;
};
#endif // !_BUTTON_H

