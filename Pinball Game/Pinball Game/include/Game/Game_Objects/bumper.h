#ifndef _BUMPER_H
#define _BUMPER_H

#include<SFML\Graphics.hpp>
#include <Graphics\circle.h>

class Bumper : public Circle, public sf::Drawable
{
	public:
		Bumper();
		Bumper(math::Vector2D pos, float radius);

		void updateMovable(float time);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::CircleShape drawObject;
};
#endif // !_BUMPER_H
