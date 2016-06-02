#include<Graphics\rectangle.h>

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(float width, float height, math::Vector2D pos, float rotation) : OBB(width, height, pos, rotation)
{
	m_centrePoints = pos;
	m_halfExtents = math::Vector2D(width, height);
	setOrientation(rotation);
}

float Rectangle::getArea()
{
	m_shapeArea = m_halfExtents.getX() * m_halfExtents.getY();
	return m_shapeArea;
}