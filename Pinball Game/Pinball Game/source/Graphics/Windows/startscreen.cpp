#include <Graphics\Windows\startscreen.h>

StartScreen::StartScreen()
{
	texture_manager = TextureManager::getInstance();
	this->loadTexture();
	this->start_screen.setTexture(this->texture_manager->getReference("startscreen"));

}

void StartScreen::loadTexture()
{
	texture_manager->loadTexture("startscreen", "assests\\main_background_art\\StartScreen.png");
}

void StartScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(start_screen);
}
