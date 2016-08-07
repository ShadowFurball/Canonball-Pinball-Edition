#pragma once

#ifndef _LIVES_H
#define _LIVES_H

#include <SFML\Graphics.hpp>
#include <Graphics\Texture\texturemanager.h>

class Lives : public sf::Drawable
{
	public:
		Lives();
		~Lives();

		void setLives(int);
		int getLives() const;

	

	private:
		int m_numberOfLives;
};
#endif // !_LIVES_H
