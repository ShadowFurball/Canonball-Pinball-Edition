#pragma once

#ifndef _COLLIDABLE_H
#define _COLLIDABLE_H

#include <Graphics\shape.h>
#include <Physics\movable.h>

class Collidable : public Movable, public Shape
{
	public:
		/*!
		Defualt Constructor	*/
		Collidable();

		/*!
		Get Mass
		Gets the mass of a colliable object
		
		@return m_mass	*/
		float getMass() const;

		/*!
		Get Inverse Mass
		Gets the inverse mass of a collidable object
		
		@return m_inversemass	*/
		float getInverseMass() const;

		/*!
		Set Mass
		Sets the mass of a colidable object
			
		@param mass	*/
		void setMass(float mass);

		/*!
		Get Elasticity
		Gets the elasticity of a collidable object
		
		@return m_restitution	*/
		float getElasticity() const;

		/*!
		Set Elasticity
		Sets the elasticity of a collidable object
		
		@param restitution	*/
		void setElasticity(float restitution);

		/*!
		Get Density
		Gets the density of a Colliable object
		
		@return m_density	*/
		float getDensity() const;
		/*!
		Set Density
		Sets the density of a collidable object
		
		@param density	*/
		void setDensity(float density);

		/*!
		Get Slop
		Gets the slop of a collidable object
		
		@return m_slop	*/
		float getSlop() const;

		/*!
		Set Slop
		Sets the slop of a collidable object	
		@param slop	*/
		void setSlop(float slop);

		/*!
		Get Percent Correction
		Gets the percent correction of a collidable object	
		@return m_percentCorrection	*/
		float getPercentCorrection() const;

		/*!
		Set Percent Correction
		Sets the percent correction of a collidable object	
		@param percentCorrection	*/
		void setPercentCorrection(float percentCorrection);

		/*!
		Get Depth
		Gets the depth of a collidable object
		@return m_depth	*/
		float getDepth() const;

		/*!
		Set Depth
		Sets the depth of a collidable object	
		@param depth	*/
		void setDepth(float depth);

		float m_inverseMass;

	protected:
		float m_mass;
		float m_restitution;
		float m_slop;
		float m_depth;
		float m_percentCorrection;
		float m_density;

		math::Vector2D m_normal;
};
#endif // !_COLLIDABLE_H