#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include<Physics\obb.h>

class Rectangle : public OBB
{
	public:
		Rectangle();
		Rectangle(float width, float height, math::Vector2D pos, float rotation);

		virtual float getArea();
		
	protected:
};
#endif // !_RECTANGLE_H
