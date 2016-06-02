#include <Physics\collisionmanager.h>

CollisionManager::CollisionManager()
{
	collision = false;

}

bool CollisionManager::ball_vs_wall(Ball *object1, Walls *object2)
{
	// set radians
	float radians;
	radians = -(object2->getOrientation()) * (float)RADIANS;

	// calculate the distance between circle and the wall
	math::Vector2D distance;
	distance = object2->getCentrePoints() - object1->getPosition();

	float distanceX = (distance.getX() * cosf(radians)) + (distance.getY() * -sinf(radians));
	float distanceY = (distance.getX() * sinf(radians)) + (distance.getY() * cosf(radians));

	distance.setX(distanceX);
	distance.setY(distanceY);

	// set the clamps
	math::Vector2D clamps = object2->getHalfExtents();

	if (distance.getX() >= 0)
	{
		clamps.setX(std::min(distance.getX(), object2->getHalfExtents().getX()));
	}
	if (distance.getX() < 0)
	{
		clamps.setX(std::max(distance.getX(), -object2->getHalfExtents().getX()));
	}
	if (distance.getY() >= 0)
	{
		clamps.setY(std::min(distance.getY(), object2->getHalfExtents().getY()));
	}
	if (distance.getY() < 0)
	{
		clamps.setY(std::max(distance.getY(), -object2->getHalfExtents().getY()));
	}

	// total distance and magnitude
	distance = distance - clamps;

	float totalDistance;
	totalDistance = distance.magnitude();
	totalDistance = totalDistance - object1->getRadius();

	if (totalDistance < 0)
	{
		float magnitude = distance.magnitude();
		if (magnitude == 0)
		{
			magnitude = 0.01f;
		}

		setDepth(totalDistance);
		setSlop(0.01f);
		setPercentCorrection(0.2f);
		setElasticity(1.f);

		float normalX = ((distance.getX() / magnitude) * cosf(radians)) + ((distance.getY() / magnitude) * sinf(radians));
		float normalY = ((distance.getX() / magnitude) * (-sinf(radians))) + ((distance.getY() / magnitude) * cosf(radians));
		m_normal.setX(normalX);
		m_normal.setY(normalY);

		// impulse resolution
		math::Vector2D relativeVel;
		relativeVel = object1->getVelocity() - object2->getVelocity();

		float relativeVelocity;
		relativeVelocity = relativeVel.dotProduct(m_normal);
		if (relativeVelocity < 0)
		{
			collision = false;
			return false;
		}

		float e = std::min(object1->getElasticity(), object2->getElasticity());
		float j = ((-(1.0f + e) * relativeVelocity) / object1->getInverseMass());
		object1->setVelocity(object1->getVelocity() + (m_normal * (j * object1->getInverseMass())));
		//object2->setVelocity(object2->getVelocity() - ((m_normal * j) * object2->getInverseMass()));


		if (object1->getMass() == 0)
		{
			object1->m_inverseMass = 0;
		}
		else
		{
			object1->getInverseMass();
		}

		// position correction
		math::Vector2D posCorrection;
		posCorrection = m_normal * (std::max((getDepth() - getSlop()), 0.0f) / (object1->getInverseMass() + object2->getInverseMass()) * getPercentCorrection());
		object1->setPosition(object1->getPosition() + posCorrection);

		collision = true;
		return true;
	}
	else
	{
		collision = false;
		return false;
	}
}

bool CollisionManager::ball_vs_barriers(Ball *object1, Barrier *object2)
{
	// set radians
	float radians;
	radians = -(object2->getOrientation()) * (float)RADIANS;

	// calculate the distance between circle and the wall
	math::Vector2D distance;
	distance = object2->getCentrePoints() - object1->getPosition();

	float distanceX = (distance.getX() * cosf(radians)) + (distance.getY() * -sinf(radians));
	float distanceY = (distance.getX() * sinf(radians)) + (distance.getY() * cosf(radians));

	distance.setX(distanceX);
	distance.setY(distanceY);

	// set the clamps
	math::Vector2D clamps = object2->getHalfExtents();

	if (distance.getX() >= 0)
	{
		clamps.setX(std::min(distance.getX(), object2->getHalfExtents().getX()));
	}
	if (distance.getX() < 0)
	{
		clamps.setX(std::max(distance.getX(), -object2->getHalfExtents().getX()));
	}
	if (distance.getY() >= 0)
	{
		clamps.setY(std::min(distance.getY(), object2->getHalfExtents().getY()));
	}
	if (distance.getY() < 0)
	{
		clamps.setY(std::max(distance.getY(), -object2->getHalfExtents().getY()));
	}

	// total distance and magnitude
	distance = distance - clamps;

	float totalDistance;
	totalDistance = distance.magnitude();
	totalDistance = totalDistance - object1->getRadius();

	if (totalDistance < 0)
	{
		float magnitude = distance.magnitude();
		if (magnitude == 0)
		{
			magnitude = 0.01f;
		}

		setDepth(totalDistance);
		setSlop(0.01f);
		setPercentCorrection(0.2f);
		setElasticity(1.f);

		float normalX = ((distance.getX() / magnitude) * cosf(radians)) + ((distance.getY() / magnitude) * sinf(radians));
		float normalY = ((distance.getX() / magnitude) * (-sinf(radians))) + ((distance.getY() / magnitude) * cosf(radians));
		m_normal.setX(normalX);
		m_normal.setY(normalY);

		// impulse resolution
		math::Vector2D relativeVel;
		relativeVel = object1->getVelocity() - object2->getVelocity();

		float relativeVelocity;
		relativeVelocity = relativeVel.dotProduct(m_normal);
		if (relativeVelocity < 0)
		{
			collision = false;
			return false;
		}

		float e = std::min(object1->getElasticity(), object2->getElasticity());
		float j = ((-(1.0f + e) * relativeVelocity) / object1->getInverseMass());
		object1->setVelocity(object1->getVelocity() + (m_normal * (j * object1->getInverseMass())));
		//object2->setVelocity(object2->getVelocity() - ((m_normal * j) * object2->getInverseMass()));


		if (object1->getMass() == 0)
		{
			object1->m_inverseMass = 0;
		}
		else
		{
			object1->getInverseMass();
		}

		// position correction
		math::Vector2D posCorrection;
		posCorrection = m_normal * (std::max((getDepth() - getSlop()), 0.0f) / (object1->getInverseMass() + object2->getInverseMass()) * getPercentCorrection());
		object1->setPosition(object1->getPosition() + posCorrection);

		collision = true;
		return true;
	}
	else
	{
		collision = false;
		return false;
	}
}

bool CollisionManager::ball_vs_paddle(Ball *object1, Paddle *object2)
{
	// set radians
	float radians;
	radians = -(object2->getOrientation()) * (float)RADIANS;

	// calculate the distance between circle and the wall
	math::Vector2D distance;
	distance = object2->getCentrePoints() - object1->getPosition();

	float distanceX = (distance.getX() * cosf(radians)) + (distance.getY() * -sinf(radians));
	float distanceY = (distance.getX() * sinf(radians)) + (distance.getY() * cosf(radians));

	distance.setX(distanceX);
	distance.setY(distanceY);

	// set the clamps
	math::Vector2D clamps = object2->getHalfExtents();

	if (distance.getX() >= 0)
	{
		clamps.setX(std::min(distance.getX(), object2->getHalfExtents().getX()));
	}
	if (distance.getX() < 0)
	{
		clamps.setX(std::max(distance.getX(), -object2->getHalfExtents().getX()));
	}
	if (distance.getY() >= 0)
	{
		clamps.setY(std::min(distance.getY(), object2->getHalfExtents().getY()));
	}
	if (distance.getY() < 0)
	{
		clamps.setY(std::max(distance.getY(), -object2->getHalfExtents().getY()));
	}

	// total distance and magnitude
	distance = distance - clamps;

	float totalDistance;
	totalDistance = distance.magnitude();
	totalDistance = totalDistance - object1->getRadius();

	if (totalDistance < 0)
	{
		float magnitude = distance.magnitude();
		if (magnitude == 0)
		{
			magnitude = 0.01f;
		}

		setDepth(totalDistance);
		setSlop(0.01f);
		setPercentCorrection(0.2f);
		setElasticity(1.f);

		float normalX = ((distance.getX() / magnitude) * cosf(radians)) + ((distance.getY() / magnitude) * sinf(radians));
		float normalY = ((distance.getX() / magnitude) * (-sinf(radians))) + ((distance.getY() / magnitude) * cosf(radians));
		m_normal.setX(normalX);
		m_normal.setY(normalY);

		// impulse resolution
		math::Vector2D relativeVel;
		relativeVel = object1->getVelocity() - object2->getVelocity();

		float relativeVelocity;
		relativeVelocity = relativeVel.dotProduct(m_normal);
		if (relativeVelocity < 0)
		{
			collision = false;
			return false;
		}

		float e = std::min(object1->getElasticity(), object2->getElasticity());
		float j = ((-(1.0f + e) * relativeVelocity) / object1->getInverseMass());
		object1->setVelocity(object1->getVelocity() + (m_normal * (j * object1->getInverseMass())));
		//object2->setVelocity(object2->getVelocity() - ((m_normal * j) * object2->getInverseMass()));


		if (object1->getMass() == 0)
		{
			object1->m_inverseMass = 0;
		}
		else
		{
			object1->getInverseMass();
		}

		// position correction
		math::Vector2D posCorrection;
		posCorrection = m_normal * (std::max((getDepth() - getSlop()), 0.0f) / (object1->getInverseMass() + object2->getInverseMass()) * getPercentCorrection());
		object1->setPosition(object1->getPosition() + posCorrection);

		collision = true;
		return true;
	}
	else
	{
		collision = false;
		return false;
	}
}

bool CollisionManager::ball_vs_bumper(Ball *object1, Bumper *object2)
{
	// distance to circle
	math::Vector2D distance;
	distance = object2->getPosition() - object1->getPosition();

	// length of distance
	float distanceLength;
	distanceLength = distance.magnitude();

	if (distanceLength < (object1->getRadius() + object2->getRadius()))
	{
		float length;
		length = distance.magnitude();
		if (length == 0)
		{
			length = 0.01f;
		}

		// collidable attributes
		setDepth(distanceLength - (object1->getRadius() + object2->getRadius()));
		setSlop(0.03f);
		setPercentCorrection(0.7f);
		setElasticity(1.f);
		m_normal = math::Vector2D((distance.getX() / length), (distance.getY() / length));

		// position correction
		math::Vector2D positionCorrection;
		float temp = (std::max(getDepth() - getSlop(), 0.0f));
		temp = temp / (object1->getInverseMass() + object2->getInverseMass());
		temp = getPercentCorrection() * temp;

		positionCorrection = m_normal * temp;

		object1->setPosition(object1->getPosition() + (positionCorrection * object1->getInverseMass()));
		object2->setPosition(object2->getPosition() + (positionCorrection * object2->getInverseMass()));

		// calculate the relative velocity
		math::Vector2D relativeVel;
		relativeVel = object1->getVelocity() - object2->getVelocity();
		float relativeNorm;
		relativeNorm = relativeVel.dotProduct(m_normal);

		// impulse resolution
		float j;
		j = -(1.0f + getElasticity());
		j = j * relativeNorm;
		j = j / (object1->getInverseMass() + object2->getInverseMass());

		// update impulse velocity
		object1->setVelocity(object1->getVelocity() + ((m_normal * j) * object1->getInverseMass()));
		object2->setVelocity(object2->getVelocity() - ((m_normal * j) * object2->getInverseMass()));

		collision = true;
		return true;
	}
	else
	{
		collision = false;
		return false;
	}
}

bool CollisionManager::getCollisionCheck()
{
	return collision;
}
