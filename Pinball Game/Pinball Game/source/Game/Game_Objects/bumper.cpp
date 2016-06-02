#include <Game\Game_Objects\bumper.h>

Bumper::Bumper()
{
}

Bumper::Bumper(math::Vector2D pos, float radius)
{
	m_position = pos;
	m_radius = radius;

	drawObject.setRadius(getRadius());
	drawObject.setOrigin(getRadius(), getRadius());
	drawObject.setPosition(m_position.getX(), m_position.getY());
}

void Bumper::updateMovable(float time)
{

}

void Bumper::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(drawObject);
}
