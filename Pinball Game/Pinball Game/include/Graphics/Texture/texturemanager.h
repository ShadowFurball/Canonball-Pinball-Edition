#pragma once

#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#include <SFML\Graphics.hpp>
#include <string>
#include <map>

class TextureManager
{
	public:
		static TextureManager* getInstance();
		void loadTexture(const std::string& name, const std::string& filename);
		void setRepeat(bool);
		sf::Texture& getReference(const std::string& texture);
		~TextureManager();
	private:
		static bool bInstanceFlag;
		static TextureManager *m_pTextures;
		std::map<std::string, sf::Texture> textures;
		sf::Texture m_texture;
		TextureManager() {};
		
};
#endif // !_TEXTUREMANAGER_H
