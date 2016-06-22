#pragma once

#ifndef _START_SCREEN_H
#define _START_SCREEN_H

#include <SFML\Graphics.hpp>
#include <Graphics\Texture\texturemanager.h>

class StartScreen : public sf::Drawable
{
	public:
		StartScreen();

		void loadTexture();
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		TextureManager *texture_manager;
		sf::Sprite start_screen;
		
};
#endif