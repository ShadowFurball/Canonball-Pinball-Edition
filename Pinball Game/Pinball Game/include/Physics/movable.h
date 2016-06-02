/*!
	@file movable.h

	This class will give our objects the ability to move. In this we have variables to 
	set the objects position, velocity and acceleration.In the update function we will 
	implement an euler eqution to give our moving objects realistic movement.

	@author Tarkan Kemalzade
*/
#pragma once

#ifndef _MOVABLE_H
#define _MOVABLE_H

#include<Math_Lib\vec2.h>

class Movable
{
	public:
		/*!
		Defualt Constructor	*/
		Movable();

		/*!
		Constructor with Parameters
		The values passed through the constructors parameters set the movable objects position,
		velocity and acceleration 
		
		@param position
		@param velocity
		@param acceleration	*/
		Movable(math::Vector2D pos, math::Vector2D vel, math::Vector2D acc);

		/*!
		Update Movable
		Updates the movable object
		
		@param time	*/
		virtual void updateMovable(float time);

		/*!
		Set Position
		Sets the position of a movable object
		
		@param position	*/
		void setPosition(math::Vector2D pos);

		/*!
		Set Velocity
		Sets the velocity of a movable object
		
		@param velocity	*/
		void setVelocity(math::Vector2D vel);

		/*!
		Set Acceleration
		Sets the acceleration of a movable object
		
		@param acceleration	*/
		void setAcceleration(math::Vector2D acc);

		/*!
		Get Position
		Gets the movable objects position
		
		@return m_position	*/
		math::Vector2D getPosition();

		/*!
		Get Velocity
		Gets the movable objects velocity 
		
		@return m_velocity	*/
		math::Vector2D getVelocity();

		/*!
		Get Acceleration
		Gets the movable objects acceleration
		
		@return m_acceleration	*/
		math::Vector2D getAcceleration();

	protected:
		math::Vector2D m_position;
		math::Vector2D m_velocity;
		math::Vector2D m_acceleration;
};
#endif // !_MOVABLE_H