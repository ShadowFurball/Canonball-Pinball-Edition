#include <GUI\button.h>

Button::Button()
{

}

Button::Button(int width, int height, math::Vector2D position)
{
	m_Position = position;
	m_Height = height;
	m_Width = width;

	m_ButtonShape.setSize(sf::Vector2f(width, height));
	m_ButtonShape.setOrigin((width / 2 ), (height / 2));
	m_ButtonShape.setPosition(position.getX(), position.getY());
	//m_ButtonShape.setFillColor(sf::Color::Transparent);
}

Button::~Button()
{
	
}

int Button::getWidth() const
{
	return this->m_Width;
}

int Button::getHeight() const
{
	return this->m_Height;
}

math::Vector2D Button::getPosition() const
{
	return this->m_Position;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_ButtonShape);
}
