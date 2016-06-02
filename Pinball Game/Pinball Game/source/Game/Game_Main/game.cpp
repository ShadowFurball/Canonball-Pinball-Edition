#include<Game\Game_Main\game.h>

Game::Game()
{
	// background
	backgroundObject.resize(3);
	backgroundObject.at(0) = Background((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), math::Vector2D((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2)), 0);
	backgroundObject.at(1) = Background((SCREEN_WIDTH_XTRA), SCREEN_HEIGHT, math::Vector2D((SCREEN_WIDTH + SCREEN_WIDTH_XTRA), (SCREEN_HEIGHT)), 0);

	// walls around the map
	wallObject.resize(3);
	//Top Wall
	wallObject.at(0) = Walls((SCREEN_WIDTH / 2), 5, math::Vector2D((SCREEN_WIDTH / 2), 5), 0);
	wallObject.at(0).setElasticity(0.6f);
	wallObject.at(0).setDensity(0.8f);
	wallObject.at(0).setMass(wallObject.at(0).getDensity());
	//Left Wall
	wallObject.at(1) = Walls(5, (SCREEN_HEIGHT / 2), math::Vector2D(5, (SCREEN_HEIGHT / 2)), 0);
	wallObject.at(1).setElasticity(0.6f);
	wallObject.at(1).setDensity(0.8f);
	wallObject.at(1).setMass(wallObject.at(0).getDensity());
	//Right Wall
	wallObject.at(2) = Walls(5, (SCREEN_HEIGHT / 2), math::Vector2D(795, (SCREEN_HEIGHT / 2)), 0);
	wallObject.at(2).setElasticity(0.6f);
	wallObject.at(2).setDensity(0.8f);
	wallObject.at(2).setMass(wallObject.at(0).getDensity());

	// barriers
	barrierObject.resize(10);
	// barrier between the game map and launcher
	barrierObject.at(0) = Barrier(5, 400, math::Vector2D(745, 590), 0);
	barrierObject.at(0).setElasticity(0.6f);
	barrierObject.at(0).setDensity(0.8f);
	barrierObject.at(0).setMass(barrierObject.at(0).getDensity());
	// barrier for the ball to enter the game
	barrierObject.at(1) = Barrier(5, 50, math::Vector2D(760, 40), -45);
	barrierObject.at(1).setElasticity(0.6f);
	barrierObject.at(1).setDensity(0.8f);
	barrierObject.at(1).setMass(barrierObject.at(0).getDensity());
	// dead zone barrier right
	barrierObject.at(2) = Barrier(100, 5, math::Vector2D(650, 850), 0);
	barrierObject.at(2).setElasticity(0.6f);
	barrierObject.at(2).setDensity(0.8f);
	barrierObject.at(2).setMass(barrierObject.at(0).getDensity());
	// dead zone barrier left
	barrierObject.at(3) = Barrier(120, 5, math::Vector2D(130, 850), 0);
	barrierObject.at(3).setElasticity(0.6f);
	barrierObject.at(3).setDensity(0.8f);
	barrierObject.at(3).setMass(barrierObject.at(0).getDensity());
	// centre blockade
	barrierObject.at(4) = Barrier(70, 5, math::Vector2D(400, 700), 0);
	barrierObject.at(4).setElasticity(0.6f);
	barrierObject.at(4).setDensity(0.8f);
	barrierObject.at(4).setMass(barrierObject.at(0).getDensity());
	//left blockade
	barrierObject.at(5) = Barrier(5, 150, math::Vector2D(190, 600), 0);
	barrierObject.at(5).setElasticity(0.6f);
	barrierObject.at(5).setDensity(0.8f);
	barrierObject.at(5).setMass(barrierObject.at(0).getDensity());
	// right blockade
	barrierObject.at(6) = Barrier(5, 150, math::Vector2D(590, 600), 0);
	barrierObject.at(6).setElasticity(0.6f);
	barrierObject.at(6).setDensity(0.8f);
	barrierObject.at(6).setMass(barrierObject.at(0).getDensity());
	//paddle barriear
	barrierObject.at(7) = Barrier(5, 20, math::Vector2D(575, 755), 55);
	barrierObject.at(7).setElasticity(0.6f);
	barrierObject.at(7).setDensity(0.8f);
	barrierObject.at(7).setMass(barrierObject.at(0).getDensity());
	barrierObject.at(8) = Barrier(5, 20, math::Vector2D(205, 755), -55);
	barrierObject.at(8).setElasticity(0.6f);
	barrierObject.at(8).setDensity(0.8f);
	barrierObject.at(8).setMass(barrierObject.at(0).getDensity());
	//corner barrier
	barrierObject.at(9) = Barrier(5, 20, math::Vector2D(20, 835), -45);
	barrierObject.at(9).setElasticity(0.6f);
	barrierObject.at(9).setDensity(0.8f);
	barrierObject.at(9).setMass(barrierObject.at(0).getDensity());

	// bumpers 
	bumperObject.resize(3);
	bumperObject.at(0) = Bumper(math::Vector2D(300, 150), 30);
	bumperObject.at(1) = Bumper(math::Vector2D(500, 150), 30);
	bumperObject.at(2) = Bumper(math::Vector2D(400, 300), 30);

	for (int i = 0; i < 3; ++i)
	{
		bumperObject.at(i).setElasticity(2);
	}

	//flipper screw
	paddleScrewObject.resize(1);
	paddleScrewObject.at(0) = PaddleScrew(math::Vector2D(563, 765), 5);
	//flipper
	paddleObject.resize(2);
	paddleObject.at(0)= Paddle(50, 5, math::Vector2D(500, 870), 0);
	paddleObject.at(0).setElasticity(0.6f);
	paddleObject.at(0).setDensity(0.8f);
	paddleObject.at(1) = Paddle(50, 5, math::Vector2D(300, 870), 0);
	paddleObject.at(1).setElasticity(0.6f);
	paddleObject.at(1).setDensity(0.8f);

	//launcher
	launcherObject = Launcher(20, 50, math::Vector2D(770, 850), 0);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Scores

	score.setText("Score", math::Vector2D(950, 130));
	score.setScoreText(score.getScore(), math::Vector2D(950, 170));

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// textures
	m_texture = TextureManager::getInstance();
	//load textures
	this->load_textures();

	this->gameInfo.setTexture(this->m_texture->getReference("gameinfo"));
	gameInfo.setPosition(backgroundObject.at(1).getPosition().getX(), backgroundObject.at(1).getPosition().getY());
	gameInfo.setOrigin(backgroundObject.at(1).getHalfExtents().getX(), backgroundObject.at(1).getHalfExtents().getY());

	this->scoreFrame.setTexture(this->m_texture->getReference("scoreFrame"));
	scoreFrame.setPosition(900, 100);

	this->background.setTexture(this->m_texture->getReference("background"));
	background.setPosition(backgroundObject.at(0).getPosition().getX(), backgroundObject.at(0).getPosition().getY());
	background.setOrigin(backgroundObject.at(0).getHalfExtents().getX(), backgroundObject.at(0).getHalfExtents().getY());

	this->canon.setTexture(this->m_texture->getReference("canon"));
	canon.setPosition(launcherObject.getPosition().getX(), launcherObject.getPosition().getY());
	canon.setOrigin(launcherObject.getHalfExtents().getX(), launcherObject.getHalfExtents().getY());
	//set textures
	barrel.resize(3);
	for (int i = 0; i < 3; ++i)
	{
		this->barrel.at(i).setTexture(this->m_texture->getReference("bumper"));
		barrel.at(i).setPosition(sf::Vector2f(bumperObject.at(i).getPosition().getX() - 2, bumperObject.at(i).getPosition().getY() - 2));
		barrel.at(i).setOrigin(bumperObject.at(i).getRadius(), bumperObject.at(i).getRadius());
	}

	wall.resize(4);
	for (int i = 0; i < 3; ++i)
	{
		this->wall.at(i).setTexture(this->m_texture->getReference("wall"));
		wall.at(i).setTextureRect(sf::IntRect(0, 0, wallObject.at(i).getHalfExtents().getX() * 2, wallObject.at(i).getHalfExtents().getY() * 2));
		wall.at(i).setPosition(sf::Vector2f(wallObject.at(i).getPosition().getX(), wallObject.at(i).getPosition().getY()));
		wall.at(i).setOrigin(wallObject.at(i).getHalfExtents().getX(), wallObject.at(i).getHalfExtents().getY());

	}

	barrier.resize(10);
	for (int i = 0; i < 10; ++i)
	{
		this->barrier.at(i).setTexture(this->m_texture->getReference("wall"));
		barrier.at(i).setTextureRect(sf::IntRect(0, 0, barrierObject.at(i).getHalfExtents().getX() * 2, barrierObject.at(i).getHalfExtents().getY() * 2));
		barrier.at(i).setPosition(sf::Vector2f(barrierObject.at(i).getPosition().getX(), barrierObject.at(i).getPosition().getY()));
		barrier.at(i).setOrigin(barrierObject.at(i).getHalfExtents().getX(), barrierObject.at(i).getHalfExtents().getY());
		barrier.at(i).setRotation(barrierObject.at(i).getOrientation());
	}

}

void Game::resetBall()
{
	// ball
	ballObject = Ball(math::Vector2D(770, 820), 15);
	ballObject.setVelocity(math::Vector2D(0, -1500));
	ballObject.setAcceleration(math::Vector2D(0, 150));
	ballObject.setDensity(0.4f);
	ballObject.setElasticity(0.8f);
	ballObject.setSlop(0.2f);
	ballObject.setMass(ballObject.getDensity());
	ballObject.setPercentCorrection(1.9f);

	this->canonball.setTexture(this->m_texture->getReference("canonball"));
	canonball.setPosition(ballObject.getPosition().getX(), ballObject.getPosition().getY());
	canonball.setOrigin(ballObject.getRadius(), ballObject.getRadius());
}

void Game::fireCanon()
{
	ballObject = Ball(math::Vector2D(770, 820), 15);
	ballObject.setVelocity(math::Vector2D(0, -1500));
	ballObject.setAcceleration(math::Vector2D(0, 150));
	ballObject.setDensity(0.4f);
	ballObject.setElasticity(0.8f);
	ballObject.setSlop(0.2f);
	ballObject.setMass(ballObject.getDensity());
	ballObject.setPercentCorrection(1.9f);

	this->canonball.setTexture(this->m_texture->getReference("canonball"));
	canonball.setPosition(ballObject.getPosition().getX(), ballObject.getPosition().getY());
	canonball.setOrigin(ballObject.getRadius(), ballObject.getRadius());
	totalScore = 5;

}

void Game::firePaddle()
{
	for (int i = 0; i < 2; ++i)
	{
		paddleObject.at(i).setVelocity(math::Vector2D(0, -400));
		//paddleObject.at(i).setAcceleration(math::Vector2D(0, -100));
		paddleObject.at(i).setDensity(0.4f);
		paddleObject.at(i).setElasticity(1.6f);
		paddleObject.at(i).setPercentCorrection(1.9f);
	}

	//paddleObject.at(0) = Paddle(50, 5, math::Vector2D(500, 830), 35);
	//paddleObject.at(1) = Paddle(50, 5, math::Vector2D(300, 830), -35);
}

void Game::resetPaddle()
{
	paddleObject.at(0) = Paddle(50, 5, math::Vector2D(500, 870), 0);
	paddleObject.at(1) = Paddle(50, 5, math::Vector2D(300, 870), 0);
}

bool Game::gameEnd()
{
	// end game phase to detect if the ball is out of bounds
	if (ballObject.getPosition().getY() > SCREEN_HEIGHT)
	{
		return true;
	}

	else
	{
		// do nothing
		return false;
	}
}

void Game::updateMovable(float time)
{
	ballObject.updateMovable(time);
	canonball.setPosition(ballObject.getPosition().getX(), ballObject.getPosition().getY());

	score.update();
	for (int i = 0; i < 2; ++i)
	{
		paddleObject.at(i).updateMovable(time);
	}
}

void Game::update()
{
	math::Vector2D point, centre;
	point.setX(paddleObject.at(0).getPosition().getX() - (paddleObject.at(0).getHalfExtents().getX() / 2));
	point.setY(paddleObject.at(0).getPosition().getY());

	centre = paddleScrewObject.at(0).getPosition();
	rotate(point, centre, 20);
}

void Game::rotate(math::Vector2D point, math::Vector2D centre, float angle)
{
	//angle = angle * RADIANS;

	float rotatedX = (cosf(angle) * (point.getX() - centre.getX())) - (sinf(angle) * (point.getY() - centre.getY())) + (centre.getX() - 50);
	float rotatedY = (sinf(angle) * (point.getX() - centre.getX())) + (cosf(angle) * (point.getY() - centre.getY())) + centre.getY();

	math::Vector2D newPosition;
	newPosition = math::Vector2D(rotatedX, rotatedY);

	paddleObject.at(0).setPosition(newPosition);
	paddleObject.at(0).setOrientation(rotatedX);
	//paddleObject.at(0).updateMovable();
}

void Game::restart(bool onRestart)
{
	if (onRestart == true)
	{
		//Reset Score, Ball Position, etc
		resetBall();
		score.setScore(0);
		
	}
	else
	{
		// do nothing
	}
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// draw objects using a const iterator
	std::vector<Background>::const_iterator BGIter;
	for (BGIter = backgroundObject.cbegin(); BGIter != backgroundObject.cend(); ++BGIter)
	{
		target.draw(*BGIter);
	}
	target.draw(background);
	target.draw(gameInfo);
	target.draw(scoreFrame);
	target.draw(score);
	target.draw(ballObject);
	target.draw(canonball);

	std::vector<Walls>::const_iterator WallIter;
	for (WallIter = wallObject.cbegin(); WallIter != wallObject.cend(); ++WallIter)
	{
		target.draw(*WallIter);
	}
	for (int i = 0; i < 4; ++i)
	{
		target.draw(wall.at(i));
	}

	
	std::vector<Barrier>::const_iterator BarrierIter;
	for (BarrierIter = barrierObject.cbegin(); BarrierIter != barrierObject.cend(); ++BarrierIter)
	{
		target.draw(*BarrierIter);
	}
	for (int i = 0; i < 10; ++i)
	{
		target.draw(barrier.at(i));
	}

	std::vector<Bumper>::const_iterator BumperIter;
	for (BumperIter = bumperObject.cbegin(); BumperIter != bumperObject.cend(); ++BumperIter)
	{
		target.draw(*BumperIter);
	}
	for (int i = 0; i < 3; ++i)
	{
		target.draw(barrel.at(i));
	}
	std::vector<PaddleScrew>::const_iterator PaddleScrewIter;
	for (PaddleScrewIter = paddleScrewObject.cbegin(); PaddleScrewIter != paddleScrewObject.cend(); ++PaddleScrewIter)
	{
		target.draw(*PaddleScrewIter);
	}

	std::vector<Paddle>::const_iterator PaddleIter;
	for (PaddleIter = paddleObject.cbegin(); PaddleIter != paddleObject.cend(); ++PaddleIter)
	{
		target.draw(*PaddleIter);
	}

	target.draw(launcherObject);
	target.draw(canon);
}

void Game::updateScore()
{
	//update the score and constaly add 1 over time
	score.setScore(totalScore);
	totalScore = totalScore + 1;
}

void Game::checkCollision()
{
	// collision detection between all game objects
	CollisionManager collisions;
	for (int i = 0; i < 3; ++i)
	{
		collisions.ball_vs_wall(&ballObject, &wallObject.at(i));
		if (collisions.ball_vs_wall(&ballObject, &wallObject.at(i)) == true)
		{
			totalScore = totalScore + 2;
		}
		
	}

	for (int i = 0; i < 1; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			collisions.ball_vs_barriers(&ballObject, &barrierObject.at(j));
			if (collisions.ball_vs_barriers(&ballObject, &barrierObject.at(j)))
			{
				totalScore = totalScore + 2;
			}

		}
	}

	for (int i = 0; i < 1; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			collisions.ball_vs_paddle(&ballObject, &paddleObject.at(j));
			if (collisions.ball_vs_paddle(&ballObject ,&paddleObject.at(j)))
			{
				totalScore = totalScore + 2;
			}
			
		}
	}

	for (int i = 0; i < 1; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			collisions.ball_vs_bumper(&ballObject, &bumperObject.at(j));
			
		}
	}

}

void Game::load_textures()
{
	m_texture->loadTexture("gameinfo", "assests\\main_background_art\\GameInfo.png");
	m_texture->loadTexture("bumper", "assests\\game_objects\\Barrel.png");
	m_texture->loadTexture("wall", "assests\\game_objects\\BarrierWall.png");
	m_texture->loadTexture("background", "assests\\game_objects\\Deck.png");
	m_texture->loadTexture("canonball", "assests\\game_objects\\Canonball.png");
	m_texture->loadTexture("canon", "assests\\game_objects\\Launcher.png");
	m_texture->loadTexture("scoreFrame", "assests\\main_background_art\\score.png");
}