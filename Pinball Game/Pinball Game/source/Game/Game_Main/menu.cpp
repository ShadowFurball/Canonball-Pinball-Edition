#include <Game\Game_Main\menu.h>

Menu::Menu()
{
	//Button Objects
	m_pButtons.resize(3);
	m_pButtons.at(0) = new Button(148, 39, math::Vector2D(250, 150));
	m_pButtons.at(1) = new Button(148, 39, math::Vector2D(250, 200));
	m_pButtons.at(2) = new Button(148, 39, math::Vector2D(250, 250));

	//////////////////////////////////////////////////////////////////////////////////////
	//Textures
	m_pTextureManager = TextureManager::getInstance();
	this->loadTexture();

	//Main Menu Textures
	m_pSprites.resize(4);

	//Background Sprites
	this->m_pSprites.at(0) = new sf::Sprite;
	this->m_pSprites.at(0)->setTexture(this->m_pTextureManager->getReference("Main Menu"));
	//Button Sprites
	this->m_pSprites.at(1) = new sf::Sprite;
	this->m_pSprites.at(1)->setTexture(this->m_pTextureManager->getReference("Button"));
	m_pSprites.at(1)->setPosition(m_pButtons.at(0)->getPosition().getX(), m_pButtons.at(0)->getPosition().getY());
	m_pSprites.at(1)->setOrigin(m_pButtons.at(0)->getWidth() / 2, m_pButtons.at(0)->getHeight() / 2);
	
	this->m_pSprites.at(2) = new sf::Sprite;
	this->m_pSprites.at(2)->setTexture(this->m_pTextureManager->getReference("Button"));
	m_pSprites.at(2)->setPosition(m_pButtons.at(1)->getPosition().getX(), m_pButtons.at(1)->getPosition().getY());
	m_pSprites.at(2)->setOrigin(m_pButtons.at(1)->getWidth() / 2, m_pButtons.at(1)->getHeight() / 2);

	this->m_pSprites.at(3) = new sf::Sprite;
	this->m_pSprites.at(3)->setTexture(this->m_pTextureManager->getReference("Button"));
	m_pSprites.at(3)->setPosition(m_pButtons.at(2)->getPosition().getX(), m_pButtons.at(2)->getPosition().getY());
	m_pSprites.at(3)->setOrigin(m_pButtons.at(2)->getWidth() / 2, m_pButtons.at(2)->getHeight() / 2);
	
	/////////////////////////////////////////////////////////////////////////////////////
	//
	// FONTS & TEXT
	m_pText.resize(3);
	
	// Fonts
	m_Font.loadFromFile("font\\Longhaul.ttf");

	//Text
	m_pText.at(0) = new sf::Text;
	m_pText.at(0)->setFont(m_Font);
	m_pText.at(0)->setString("Play");
	m_pText.at(0)->setCharacterSize(30);
	m_pText.at(0)->setColor(sf::Color::Black);
	m_pText.at(0)->setPosition((m_pSprites.at(1)->getPosition().x + 45), (m_pSprites.at(1)->getPosition().y));
	m_pText.at(0)->setOrigin(m_pSprites.at(1)->getOrigin());

	m_pText.at(1) = new sf::Text;
	m_pText.at(1)->setFont(m_Font);
	m_pText.at(1)->setString("Options");
	m_pText.at(1)->setCharacterSize(30);
	m_pText.at(1)->setColor(sf::Color::Black);
	m_pText.at(1)->setPosition((m_pSprites.at(2)->getPosition().x + 20), (m_pSprites.at(2)->getPosition().y));
	m_pText.at(1)->setOrigin(m_pSprites.at(2)->getOrigin());

	m_pText.at(2) = new sf::Text;
	m_pText.at(2)->setFont(m_Font);
	m_pText.at(2)->setString("Quit");
	m_pText.at(2)->setCharacterSize(30);
	m_pText.at(2)->setColor(sf::Color::Black);
	m_pText.at(2)->setPosition((m_pSprites.at(3)->getPosition().x - 35), (m_pSprites.at(3)->getPosition().y - 15));
	m_pText.at(0)->setOrigin(m_pSprites.at(3)->getOrigin());


}

Menu::~Menu()
{

}

void Menu::loadTexture()
{
	m_pTextureManager->loadTexture("Main Menu", "assests\\main_background_art\\menuscreen.png");
	m_pTextureManager->loadTexture("Button", "assests\\main_background_art\\Button.png");
}

void Menu::deleteObjects()
{
	std::vector<Button*>::iterator button;
	for (button = m_pButtons.begin(); button != m_pButtons.end(); ++button)
	{
		delete[] (*button);
	}
	m_pButtons.clear();

	std::vector<sf::Sprite*>::iterator sprites;
	for (sprites = m_pSprites.begin(); sprites != m_pSprites.end(); ++sprites)
	{
		delete[] (*sprites);
	}
	m_pSprites.clear();

	std::vector<sf::Text*>::iterator text;
	for (text = m_pText.begin(); text != m_pText.end(); ++text)
	{
		delete[](*text);
	}
	m_pText.clear();

	//delete[] m_pTextureManager;
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//target.draw(m_BackgroundImage);

	std::vector<sf::Sprite*>::const_iterator sprites;
	for (sprites = m_pSprites.cbegin(); sprites != m_pSprites.cend(); ++sprites)
	{
		target.draw(**sprites);
	}

	std::vector<Button*>::const_iterator button;
	for (button = m_pButtons.cbegin(); button != m_pButtons.cend(); ++button)
	{
		target.draw(**button); // dereference the iterator and the pointer.
	}

	std::vector<sf::Text*>::const_iterator text;
	for (text = m_pText.cbegin(); text != m_pText.cend(); ++text)
	{
		target.draw(**text);
	}
}
