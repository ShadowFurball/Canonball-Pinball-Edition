/*!
	@file shape.h

	Abstract class with virtual functions which define the main 
	aspects of a shape.

	@author Tarkan Kemalzade
*/
#pragma once

#ifndef _SHAPE_H
#define _SHAPE_H

class Shape
{
	protected:
		float m_shapeArea;

	public:
		Shape();
		virtual float getArea();
};

#endif // !_SHAPE_H
