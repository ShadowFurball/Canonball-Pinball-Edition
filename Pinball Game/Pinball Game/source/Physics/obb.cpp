#include<Physics\obb.h>

OBB::OBB() : AABB(0, 0, math::Vector2D(0, 0))
{

}

OBB::OBB(float width, float height, math::Vector2D pos, float rotation) : AABB(width, height, pos)
{
	m_halfExtents = math::Vector2D(width, height);
	m_centrePoints = pos;
	m_oreintation = rotation;
}

void OBB::setOrientation(float angle)
{
	m_oreintation = angle;
}

float OBB::getOrientation() const
{
	return m_oreintation;
}