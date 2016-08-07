#pragma once

#ifndef _GAME_H
#define _GAME_H

#define SCREEN_WIDTH (800)
#define SCREEN_WIDTH_XTRA (500)
#define SCREEN_HEIGHT (900)

#include<Physics\collisionmanager.h>
#include<Game\Game_Main\background.h>
#include<Game\Game_Objects\ball.h>
#include<Game\Game_Objects\bumper.h>
#include<Game\Game_Objects\walls.h>
#include<Game\Game_Objects\barriers.h>
#include<Game\Game_Objects\paddle.h>
#include<Game\Game_Objects\paddlescrew.h>
#include<Game\Game_Objects\launcher.h>
#include<Graphics\Texture\texturemanager.h>
#include <Utilities\inputmanager.h>
#include <Game\Game_Info\lives.h>
#include<Game\Game_Info\score.h>
#include<vector>

class Game : public sf::Drawable
{
	public:
		Game();
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		void updateMovable(float time);
		void update();
		void updateScore();
		void fireCanon();
		void rotate(math::Vector2D point, math::Vector2D centre, float angle);
		void checkCollision();
		void resetBall();
		void gameEnd();
		void restart(bool);
		bool getIsEnded();

		void firePaddle();
		void resetPaddle();

	protected:
		TextureManager *m_texture;
		std::vector<sf::Sprite> wall;
		std::vector<sf::Sprite> barrel;
		std::vector<sf::Sprite> barrier;
		sf::Sprite background;
		sf::Sprite gameInfo;
		sf::Sprite canonball;
		sf::Sprite canon;
		Score score;
		sf::Sprite scoreFrame;

	private:
		std::vector<Background> backgroundObject;
		Ball ballObject;
		std::vector<Bumper> bumperObject;
		std::vector<Walls> wallObject;
		std::vector<Barrier> barrierObject;
		std::vector<Paddle> paddleObject;
		std::vector<PaddleScrew> paddleScrewObject;
		Launcher launcherObject;
		void load_textures();
		//InputManager displayLives;


		int totalScore;
		bool m_IsEnded;
		
};
#endif // !_GAME_H