#pragma once

#ifndef _BUTTON_H
#define _BUTTON_H

#include <Graphics\rectangle.h>
#include <SFML\Graphics.hpp>

class Button : public sf::Drawable
{
	public:
		Button();
		Button(int, int, math::Vector2D);
		~Button();

		int getWidth() const;
		int getHeight() const;
		math::Vector2D getPosition() const;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		sf::RectangleShape m_ButtonShape;
		int m_Width;
		int m_Height;
		math::Vector2D m_Position;
};
#endif // !_BUTTON_H

