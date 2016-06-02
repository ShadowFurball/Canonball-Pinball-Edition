#pragma once

#ifndef _COLLISIONMANAGER_H
#define _COLLISIONMANAGER_H

#include<Physics\collidable.h>
#include<Game\Game_Objects\ball.h>
#include<Game\Game_Objects\bumper.h>
#include<Game\Game_Objects\walls.h>
#include<Game\Game_Objects\barriers.h>
#include<Game\Game_Objects\paddle.h>

class CollisionManager : public Collidable
{
	public:
		CollisionManager();

		bool ball_vs_wall(Ball *object1, Walls *object2);
		bool ball_vs_barriers(Ball *object1, Barrier *object2);
		bool ball_vs_paddle(Ball *object1, Paddle *object2);
		bool ball_vs_bumper(Ball *object1, Bumper *object2);

		bool getCollisionCheck();
		bool collision;
protected:
	
};
#endif // !_COLLISIONMANAGER_H