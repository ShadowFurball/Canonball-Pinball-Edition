#include <Physics\aabb.h>

AABB::AABB()
{
	m_centrePoints.setX(0);
	m_centrePoints.setY(0);

	m_halfExtents.setX(0);
	m_halfExtents.setY(0);
}

AABB::AABB(float width, float height, math::Vector2D pos)
{
	m_centrePoints.setX(pos.getX());
	m_centrePoints.setX(pos.getY());

	m_halfExtents.setX(width);
	m_halfExtents.setY(height);
}

math::Vector2D AABB::getCentrePoints() const
{
	return m_centrePoints;
}

math::Vector2D AABB::getHalfExtents() const
{
	return m_halfExtents;
}