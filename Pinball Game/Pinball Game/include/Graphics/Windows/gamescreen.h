#ifndef _GAMESCREEN_H
#define _GAMESCREEN_H

#include<SFML\Graphics.hpp>

class GameScreen
{
	enum gamestate{INITIALISE, GAME_MAIN, GAME_END};
	public:
		GameScreen();

	private:
		sf::RenderWindow m_window;
		gamestate game_state;
};
#endif // !_GAMESCREEN