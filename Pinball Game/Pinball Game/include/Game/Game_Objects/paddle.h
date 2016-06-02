#ifndef _PADDLE_H
#define _PADDLE_H

#include<SFML\Graphics.hpp>
#include<Graphics\rectangle.h>

class Paddle : public Rectangle, public sf::Drawable
{
	public:
		Paddle();
		Paddle(float width, float height, math::Vector2D pos, float rotation);

		void updateMovable(float time);
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		sf::RectangleShape drawObject;
};
#endif // !_PADDLE_H
