#ifndef _BARRIERS_H
#define _BARRIERS_H

#include<SFML\Graphics.hpp>
#include<Graphics\rectangle.h>

class Barrier : public Rectangle, public sf::Drawable
{
	public:
		Barrier();
		Barrier(float width, float height, math::Vector2D pos, float rotation);

		void updateMovable(float time);
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		sf::RectangleShape drawObject;
};
#endif // !_BARRIERS_H
