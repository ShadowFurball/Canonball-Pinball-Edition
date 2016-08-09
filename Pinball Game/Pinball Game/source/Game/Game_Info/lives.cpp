#include <Game\Game_Info\lives.h>

Lives::Lives()
{
	m_numberOfLives = 0;
}

Lives::~Lives()
{

}

void Lives::setLives(int numberOfLives)
{
	m_numberOfLives = numberOfLives;
}

int Lives::getLives() const
{
	return m_numberOfLives;
}

void Lives::setText(std::string text, math::Vector2D position)
{
	m_LivesLabel.setFont(m_LivesFont);
	m_LivesLabel.setString(text);
	m_LivesLabel.setCharacterSize(40);
	m_LivesLabel.setColor(sf::Color::Red);
	m_LivesLabel.setPosition(position.getX(), position.getY());
}

