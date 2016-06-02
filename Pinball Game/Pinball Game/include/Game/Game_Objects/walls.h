#ifndef _WALLS_H
#define _WALLS_H

#include<SFML\Graphics.hpp>
#include<Graphics\rectangle.h>

class Walls : public Rectangle, public sf::Drawable
{
	public:
		Walls();
		Walls(float width, float height, math::Vector2D pos, float rotation);

		void updateMovable(float time);
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		sf::RectangleShape drawObject;
};
#endif // !_WALLS_H
