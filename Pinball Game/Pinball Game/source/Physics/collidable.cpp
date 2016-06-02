#include <Physics\collidable.h>

Collidable::Collidable()
{
	m_mass = 0;
	m_inverseMass = 0;
	m_restitution = 0;
	m_slop = 0;
	m_depth = 0;
	m_percentCorrection = 0;
	m_density = 0;
}

float Collidable::getMass() const
{
	return m_mass;
}

float Collidable::getInverseMass() const
{
	return m_inverseMass;
}

void Collidable::setMass(float mass)
{
	m_mass = mass * getArea();
	m_inverseMass = 1 / m_mass;
}

float Collidable::getElasticity() const
{
	return m_restitution;
}

void Collidable::setElasticity(float restitution)
{
	m_restitution = restitution;
}

float Collidable::getDensity() const
{
	return m_density;
}

void Collidable::setDensity(float density)
{
	m_density = density;
}

float Collidable::getSlop() const
{
	return m_slop;
}

void Collidable::setSlop(float slop)
{
	m_slop = slop;
}

float Collidable::getPercentCorrection() const
{
	return m_percentCorrection;
}

void Collidable::setPercentCorrection(float percentCorrection)
{
	m_percentCorrection = percentCorrection;
}

float Collidable::getDepth() const
{
	return m_depth;
}

void Collidable::setDepth(float depth)
{
	m_depth = depth;
}