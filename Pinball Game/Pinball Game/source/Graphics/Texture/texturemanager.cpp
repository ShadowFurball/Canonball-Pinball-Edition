#include <Graphics\Texture\texturemanager.h>

bool TextureManager::bInstanceFlag = false;
TextureManager* TextureManager::m_pTextures = nullptr;

TextureManager * TextureManager::getInstance()
{
	if (!bInstanceFlag)
	{
		m_pTextures = new TextureManager();
		bInstanceFlag = true;
		return m_pTextures;
	}
	else
	{
		return m_pTextures;
	}
}

void TextureManager::loadTexture(const std::string & name, const std::string & filename)
{
	m_texture.loadFromFile(filename);

	//Add to a list of textures
	this->textures[name] = m_texture;
	return;
}

void TextureManager::setRepeat(bool onRepeat)
{
	m_texture.setRepeated(onRepeat);
}

sf::Texture & TextureManager::getReference(const std::string & texture)
{
	// TODO: insert return statement here
	return this->textures.at(texture);
}

TextureManager::~TextureManager()
{
	bInstanceFlag = false;
}
