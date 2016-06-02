#include <Game\Game_Objects\paddlescrew.h>

PaddleScrew::PaddleScrew()
{
}

PaddleScrew::PaddleScrew(math::Vector2D pos, float radius)
{
	m_position = pos;
	m_radius = radius;

	drawObject.setRadius(getRadius());
	drawObject.setOrigin(getRadius(), getRadius());
	drawObject.setFillColor(sf::Color::Black);
	drawObject.setPosition(m_position.getX(), m_position.getY());
}

void PaddleScrew::updateMovable(float time)
{
}

void PaddleScrew::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(drawObject);
}
