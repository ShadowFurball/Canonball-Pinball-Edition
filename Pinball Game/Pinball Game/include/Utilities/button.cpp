#include <Utilities\button.h>

Button::Button()
{

}

Button::Button(int width, int height, math::Vector2D position)
{
	m_halfExtents.setX(width);
	m_halfExtents.setY(height);

	m_centrePoints = position;
	m_position = position;

	m_ButtonShape.setSize(sf::Vector2f((getHalfExtents().getX() * 2), (getHalfExtents().getY() * 2)));
	m_ButtonShape.setOrigin(getHalfExtents().getX(), getHalfExtents().getY());
	m_ButtonShape.setPosition(getPosition().getX(), getPosition().getY());
}

Button::~Button()
{
	
}


void Button::updateImage(ButtonState imageState)
{
	switch (imageState)
	{
		case DEFAULT:
			break;

		case HOVERED:
			break;

		case CLICKED:
			break;
	}
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates ststes) const
{
	target.draw(m_ButtonShape);
}