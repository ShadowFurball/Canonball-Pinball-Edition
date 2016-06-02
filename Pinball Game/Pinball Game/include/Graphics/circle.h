/*!
	@file circle.h

	Holds data which represent a circle

	@author Tarkan K*/

#ifndef _CIRCLE_H
#define _CIRCLE_H

#include<Physics\collidable.h>

class Circle : public Collidable
{
	public:
		Circle();
		Circle(math::Vector2D pos, float radius);

		virtual float getArea();

		void setRadius(float radius);
		float getRadius() const;

	protected:
		float m_radius;
};
#endif // !_CIRCLE_H