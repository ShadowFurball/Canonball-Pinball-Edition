#pragma once

#ifndef _OBB_H
#define _OBB_H

#include <Physics\aabb.h>

class OBB : public AABB
{
	public:
		OBB();
		OBB(float width, float height, math::Vector2D pos, float rotation);

		void setOrientation(float angle);
		
		float getOrientation() const;

	protected:
		float m_oreintation;
};
#endif // !_OBB_H
