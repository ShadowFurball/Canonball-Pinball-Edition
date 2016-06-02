#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#include <iostream>

#define PI (3.14159265359)
#define RADIANS (PI / 180)

namespace math 
{
	class Vector2D
	{
		public:
			//Constructors
			Vector2D();
			Vector2D(float x, float y);
		
			//Setters
			void setX(float x);
			void setY(float y);
		
			//Getters
			float getX();
			float getY();
		
			//Mathematical operations
			float magnitude();
			Vector2D normalise();
			float dotProduct(Vector2D &vector);
		
			//Basic Operations
			Vector2D operator+(Vector2D &vector);
			Vector2D operator+(float scalar);
			Vector2D operator-(Vector2D &vector);
			Vector2D operator-(float scalar);
			Vector2D operator/(Vector2D &vector);
			Vector2D operator/(float scalar);
			Vector2D operator*(Vector2D &vector);
			Vector2D operator*(float scalar);
		
			//Assignment Operations]
			Vector2D operator=(Vector2D &vector);
			Vector2D operator=(float scalar);
			Vector2D operator+=(Vector2D &vector);
			Vector2D operator+=(float scalar);
			Vector2D operator-=(Vector2D &vector);
			Vector2D operator-=(float scalar);
			Vector2D operator*=(Vector2D &vector);
			Vector2D operator*=(float scalar);
			Vector2D operator/=(Vector2D &vector);
			Vector2D operator/=(float scalar);
		
			//Bool Operations
			bool operator==(Vector2D &vector);
			bool operator!=(Vector2D &vector);
			bool operator>(Vector2D &vector);
			bool operator<(Vector2D &vector);
		
		public:
			float m_x;
			float m_y;
	};
}

#endif