#include <Utilities\inputmanager.h>

InputManager::InputManager()
{
	m_text = "";
	m_number = 0;
}

InputManager::~InputManager()
{

}

void InputManager::stringToBeDisplayed(std::string text)
{
	m_text = text;
}

void InputManager::integerToBeDisplayed(int number)
{
	m_number = number;
}

sf::Font InputManager::assignFont(std::string filename) 
{
	m_fontType.loadFromFile(filename);
	return m_fontType;
}

std::string InputManager::getString() const
{
	return m_text;
}

int InputManager::getInterger() const
{
	return m_number;
}

std::string InputManager::intToString(int number)
{
	std::string convertedString;
	convertedString = std::to_string(getInterger());

	return convertedString;
}

void InputManager::setTextAttributes(sf::Font font, sf::Color colour, int textSize, math::Vector2D position)
{
	m_textType.setFont(font);
	m_textType.setColor(colour);
	m_textType.setCharacterSize(textSize);
	m_textType.setPosition(sf::Vector2f(position.getX(), position.getY()));
}

void InputManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_textType);
}