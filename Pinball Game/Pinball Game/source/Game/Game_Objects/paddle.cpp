#include <Game\Game_Objects\paddle.h>

Paddle::Paddle()
{
}

Paddle::Paddle(float width, float height, math::Vector2D pos, float rotation)
{
	m_halfExtents.setX(width);
	m_halfExtents.setY(height);

	m_centrePoints = pos;
	m_position = m_centrePoints;

	m_oreintation = rotation;

	drawObject.setRotation(getOrientation());
	drawObject.setSize(sf::Vector2f((m_halfExtents.getX() * 2), (m_halfExtents.getY() * 2)));
	drawObject.setOrigin(m_halfExtents.getX(), m_halfExtents.getY());
	drawObject.setPosition(m_position.getX(), m_position.getY());
}

void Paddle::updateMovable(float time)
{
	m_velocity = m_velocity + (m_acceleration * time);
	m_position = m_position + (m_velocity * time);

	m_centrePoints = m_position;

	drawObject.setPosition(m_centrePoints.getX(), m_centrePoints.getY());
}


void Paddle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(drawObject);
}
