#include <Game\Game_Objects\walls.h>

Walls::Walls()
{
}

Walls::Walls(float width, float height, math::Vector2D pos, float rotation)
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

void Walls::updateMovable(float time)
{
}

void Walls::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(drawObject);
}