#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H

#include <SFML\Graphics.hpp>
#include <Math_Lib\vec2.h>
#include <string>

class InputManager : public sf::Drawable
{
	public:
		InputManager();
		~InputManager();

		void stringToBeDisplayed(std::string);
		void integerToBeDisplayed(int);
		void setTextAttributes(sf::Font, sf::Color, int, math::Vector2D);

		std::string getString() const;
		std::string intToString(int);
		int getInterger() const;
		sf::Font assignFont(std::string);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;


	private:
		sf::Font m_fontType;
		sf::Text m_textType;
		std::string m_text;
		int m_number;
};
#endif // !_INPUTMANAGER_H
