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