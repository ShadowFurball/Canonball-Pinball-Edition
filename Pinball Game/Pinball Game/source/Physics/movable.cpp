#include <Physics\movable.h>

Movable::Movable()
{
	m_position = math::Vector2D(0, 0);
	m_velocity = math::Vector2D(0, 0);
	m_acceleration = math::Vector2D(0, 0);
}

Movable::Movable(math::Vector2D pos, math::Vector2D vel, math::Vector2D acc)
{
	m_position = pos;
	m_velocity = vel;
	m_acceleration = acc;
}

void Movable::updateMovable(float time)
{

}

void Movable::setPosition(math::Vector2D pos)
{
	m_position = pos;
}

void Movable::setVelocity(math::Vector2D vel)
{
	m_velocity = vel;
}

void Movable::setAcceleration(math::Vector2D acc)
{
	m_acceleration = acc;
}

math::Vector2D Movable::getPosition()
{
	return m_position;
}

math::Vector2D Movable::getVelocity()
{
	return m_velocity;
}

math::Vector2D Movable::getAcceleration()
{
	return m_acceleration;
}