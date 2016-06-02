#include<Graphics\circle.h>

Circle::Circle()
{
	m_radius = 0;
}

Circle::Circle(math::Vector2D pos, float radius)
{
	m_position = pos;
	m_radius = radius;
}

void Circle::setRadius(float radius)
{
	m_radius = radius;
}

float Circle::getRadius() const
{
	return m_radius;
}

float Circle::getArea()
{
	m_shapeArea = (float)PI * powf(m_radius, 2);
	return m_shapeArea;
}