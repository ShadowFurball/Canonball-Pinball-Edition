#pragma once

#ifndef _MENU_H
#define _MENU_H

#include <SFML\Graphics.hpp>
#include <Graphics\Texture\texturemanager.h>
#include <Game\Game_Main\background.h>
#include <GUI\button.h>

#include <vector>

class Menu : public sf::Drawable
{
	public:
		Menu();
		~Menu();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void loadTexture();
		void deleteObjects();

		std::vector<sf::Sprite*> m_pSprites;

	protected:

	private:
		TextureManager* m_pTextureManager;
		std::vector<sf::Text*> m_pText;
		sf::Font m_Font;
		std::vector<Button*> m_pButtons;

};
#endif // !_MENU_H

