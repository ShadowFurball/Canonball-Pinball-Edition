#pragma once

#ifndef _SCORE_H
#define _SCORE_H

#include <SFML\Graphics.hpp>
#include <Math_Lib\vec2.h>
#include <string>
#include <Graphics\Texture\texturemanager.h>

class Score : public sf::Drawable
{
public:
	Score();

	int getScore() const;
	void setScore(int);

	void setText(std::string, math::Vector2D);
	void setScoreText(int, math::Vector2D);

	void update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

protected:
	int m_score;

	sf::Font m_scoreLabelFont;
	sf::Font m_scoreTextFont;
	sf::Text m_scoreLabel;
	sf::Text m_scoreText;

};

#endif