#ifndef _GAMESCREEN_H
#define _GAMESCREEN_H

#include<SFML\Graphics.hpp>
#include <Game\Game_Main\game.h>
#include <Game\Game_Main\menu.h>
#include <Graphics\Windows\startscreen.h>

class GameScreen
{
	enum gamestate{INITIALISE, GAME_MAIN, GAME_END};
	enum GameWindow{START_SCREEN, GAME_SREEN, GAME_OVER_SCREEN};
	public:
		GameScreen();

		int getWindowHeight() const;
		void setWindowHeight(int);

		int getWindowWidth() const;
		void setWindowWidth(int);

		void runStartScreen();
		void runMenuScreen();
		void runGameScreen();

	private:
		sf::RenderWindow m_window;
		int m_windowHeight;
		int m_windowWidth;
		gamestate game_state;
		GameWindow game_screens;

		Game game;
		StartScreen startScreen;
};
#endif // !_GAMESCREEN