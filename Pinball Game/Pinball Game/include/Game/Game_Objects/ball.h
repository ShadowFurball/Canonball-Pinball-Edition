#ifndef _BALL_H
#define _BALL_H

#include<SFML\Graphics.hpp>
#include <Graphics\circle.h>

class Ball : public Circle, public sf::Drawable
{
	public:
		Ball();
		Ball(math::Vector2D pos, float radius);

		void updateMovable(float time);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::CircleShape drawObject;
};
#endif // !_BALL_H
