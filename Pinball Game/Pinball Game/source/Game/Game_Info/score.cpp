#include <Game\Game_Info\score.h>

Score::Score()
{
	m_scoreLabelFont.loadFromFile("font\\Arista.TTF");
	m_scoreTextFont.loadFromFile("font\\DYMOGBE_.TTF");

	m_score = 0;
}

int Score::getScore() const
{
	return m_score;
}

void Score::setScore(int score)
{
	m_score =+ score;
}

void Score::setText(std::string text, math::Vector2D pos)
{
	m_scoreLabel.setFont(m_scoreLabelFont);
	m_scoreLabel.setString(text);
	m_scoreLabel.setCharacterSize(40);
	m_scoreLabel.setColor(sf::Color::Black);
	m_scoreLabel.setPosition(pos.getX(), pos.getY());
}

void Score::update()
{
	std::string scoreAsString;
	scoreAsString = std::to_string(getScore());

	m_scoreText.setFont(m_scoreTextFont);
	m_scoreText.setCharacterSize(40);
	m_scoreText.setColor(sf::Color::Black);
	m_scoreText.setString(scoreAsString);
}

void Score::setScoreText(int score, math::Vector2D pos)
{
	setScore(score);

	std::string scoreAsString;
	scoreAsString = std::to_string(getScore());

	m_scoreText.setFont(m_scoreTextFont);
	m_scoreText.setCharacterSize(40);
	m_scoreText.setColor(sf::Color::Black);
	m_scoreText.setPosition(pos.getX(), pos.getY());
	m_scoreText.setString(scoreAsString);
}


void Score::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_scoreLabel);
	target.draw(m_scoreText);
}
