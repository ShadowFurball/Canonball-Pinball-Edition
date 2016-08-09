#pragma once

#ifndef _LIVES_H
#define _LIVES_H

#include <SFML\Graphics.hpp>
#include <Graphics\Texture\texturemanager.h>
#include <Math_Lib\vec2.h>

class Lives : public sf::Drawable
{
	public:
		Lives();
		~Lives();

		void setLives(int);
		int getLives() const;

		void setText(std::string, math::Vector2D);
		void setScoreText(int, math::Vector2D);

	//	void update();
	//	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		int m_numberOfLives;

		sf::Text m_LivesLabel;
		sf::Font m_LivesFont;
};
#endif // !_LIVES_H
