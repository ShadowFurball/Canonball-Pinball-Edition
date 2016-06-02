#ifndef _PADDLESCREW_H
#define _PADDLESCREW_H

#include<SFML\Graphics.hpp>
#include <Graphics\circle.h>

class PaddleScrew : public Circle, public sf::Drawable
{
public:
	PaddleScrew();
	PaddleScrew(math::Vector2D pos, float radius);

	void updateMovable(float time);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::CircleShape drawObject;
};
#endif // !_PADDLESCREW_H