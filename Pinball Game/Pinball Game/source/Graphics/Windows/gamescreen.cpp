#include<Graphics\Windows\gamescreen.h>

GameScreen::GameScreen()
{	
	
	
	game_screens = START_SCREEN;

	if (game_screens == START_SCREEN)
	{
		setWindowWidth(500);
		setWindowHeight(500);
		m_window.setSize(sf::Vector2u(getWindowWidth(), getWindowHeight()));
	}
	if (game_screens == GAME_SREEN)
	{
		setWindowWidth(1300);
		setWindowHeight(900);
		m_window.setSize(sf::Vector2u(getWindowWidth(), getWindowHeight()));
	}
	
	m_window.create(sf::VideoMode(getWindowWidth(), getWindowHeight()), "Canonball");
	
	switch (game_screens)
	{
	case START_SCREEN:
		runStartScreen();
		break;

	case GAME_SREEN:
		runGameScreen();
		break;
	}
}

void GameScreen::runStartScreen()
{
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				m_window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
				game_screens = GAME_SREEN;

				if (game_screens == GAME_SREEN)
				{
					runGameScreen();
				}
			}
		}

		m_window.clear();
		m_window.draw(startScreen);
		m_window.display();
	}
}

void GameScreen::runGameScreen()
{
	setWindowWidth(1300);
	setWindowHeight(900);
	m_window.setSize(sf::Vector2u(getWindowWidth(), getWindowHeight()));
	m_window.create(sf::VideoMode(getWindowWidth(), getWindowHeight()), "Canonball");
	sf::Clock gameTime;
	sf::Clock scoreTimer;


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
					game.fireCanon();
					canonFired = true;
				}

			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				m_window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				if (paddleFired == true)
				{
					game.firePaddle();
				}
				else
				{

				}
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				if (paddleFired == true)
				{
					game.resetPaddle();
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
		}	break;


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
					game.updateMovable(elapsedTime);
					//build_game.update();
					game.checkCollision();
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

				game.updateScore();
				scoreTimer.restart();
			}

			////// END GAME NEEDS FIXING
			game.gameEnd();

			if (game.getIsEnded() != true)
			{
				game_state = GAME_END;
			}
		}	break;


		case GAME_END:
		{
			if (game_state == GAME_END)
			{
				game.resetBall();
				game_state = INITIALISE;
			}
		}	break;

		}

		m_window.clear();
		m_window.draw(game);
		m_window.display();
		
	}
}

int GameScreen::getWindowHeight() const
{
	return m_windowHeight;
}
void GameScreen::setWindowHeight(int height)
{
	m_windowHeight = height;
}

int GameScreen::getWindowWidth() const
{
	return m_windowWidth;
}
void GameScreen::setWindowWidth(int width)
{
	m_windowWidth = width;
}


