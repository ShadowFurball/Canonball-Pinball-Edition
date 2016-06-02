#include <Game\Game_Objects\ball.h>

Ball::Ball()
{

}

Ball::Ball(math::Vector2D pos, float radius)
{
	m_position = pos;
	m_radius = radius;

	drawObject.setRadius(getRadius());
	drawObject.setOrigin(getRadius(), getRadius());
	drawObject.setPosition(m_position.getX(), m_position.getY());
}

void Ball::updateMovable(float time)
{
	m_velocity = m_velocity + (m_acceleration * time);
	m_position = m_position + (m_velocity * time);

	drawObject.setPosition(m_position.getX(), m_position.getY());
}

void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(drawObject);
}