#include<Graphics\Windows\gamescreen.h>
#include <Game\Game_Main\game.h>

GameScreen::GameScreen()
{
	m_window.create(sf::VideoMode(1300, 1000), "Canonball");
	
	sf::Clock gameTime;
	sf::Clock scoreTimer;
	Game build_game;

	bool canonFired;
	bool paddleFired = false;
	bool restert = false;
	game_state = INITIALISE;

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
				if (canonFired == false)
				{
					build_game.fireCanon();
					canonFired = true;
				}
				
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				if (paddleFired == true)
				{
					build_game.firePaddle();
				}
				else
				{

				}
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				if (paddleFired == true)
				{
					build_game.resetPaddle();
				}
				else
				{

				}
			}
		}

		switch (game_state)
		{
			case INITIALISE:
			{
				canonFired = false;
				paddleFired = false;
				game_state = GAME_MAIN;
			}

			case GAME_MAIN:
			{
				paddleFired = true;
				float elapsedTime = gameTime.getElapsedTime().asSeconds();

				if (elapsedTime > 0.005)
				{
					if (elapsedTime > 0.005)
					{
						elapsedTime = (float)0.005;
					}

					if (canonFired == true)
					{
						build_game.updateMovable(elapsedTime);
						//build_game.update();
						build_game.checkCollision();
					}

					gameTime.restart();
				}

				float scoreTime = scoreTimer.getElapsedTime().asSeconds();
				if (scoreTime > 0.5)
				{
					if (scoreTime > 0.5)
					{
						scoreTime = 0.5;
					}

					build_game.updateScore();
					scoreTimer.restart();
				}

				////// END GAME NEEDS FIXING
				if (build_game.gameEnd() == true)
				{
					restert = true;
					game_state = GAME_END;
				}
			}

			case GAME_END:
			{
				build_game.restart(restert);
				game_state = INITIALISE;
			}
		}

		m_window.clear();
		m_window.draw(build_game);
		m_window.display();
	}
}

