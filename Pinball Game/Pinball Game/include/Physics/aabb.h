#pragma once

#ifndef _AABB_H
#define _AABB_H

#include<Physics\collidable.h>

class AABB : public Collidable
{
	public:
		/*!
		Defualt Constructor	*/
		AABB();

		/*!
		AABB
		Sets the AABB's width, height, position, restitution and density 
		
		@param width
		@param height
		@param position  
		@param restitution
		@param density	*/
		AABB(float width, float height, math::Vector2D pos);

		/*!
		Get Centre Points
		Gets the centre points of a axis aligned bounding box	
		
		@return m_centrePoints	*/
		math::Vector2D getCentrePoints() const;

		/*!
		Gets Half Extents
		Gets the ha;f extents of axis aligned bounding box
		
		@return m_halfExtents	*/
		math::Vector2D getHalfExtents() const;
		
	protected:
		math::Vector2D m_centrePoints;
		math::Vector2D m_halfExtents;
};
#endif // !_AABB_H