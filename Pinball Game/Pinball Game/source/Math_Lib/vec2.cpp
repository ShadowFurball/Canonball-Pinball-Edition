/**
@file Vector2D.cpp
*/

#include<Math_Lib\vec2.h>

using namespace math;

Vector2D::Vector2D()
{
	m_x = 0;
	m_y = 0;
}

Vector2D::Vector2D(float x, float y)
{
	m_x = x;
	m_y = y;
}

/**
Sets the vectors x coordinate.
@param x (float) - vectors x coordinate.
*/
void Vector2D::setX(float x)
{
	m_x = x;
}

/**
Sets the vectors y coordinate.
@param y (float) - vectors y coordinate.
*/
void Vector2D::setY(float y)
{
	m_y = y;
}

/**
Returns the x coordinate of a vector.
@return m_x (float) - x coordinate of a vector.
*/
float Vector2D::getX()
{
	return m_x;
}

/**
Returns the y coordinate of a vector.
@return m_y (float) - y coordinate of a vector.
*/
float Vector2D::getY()
{
	return m_y;
}

/**
Calculates then returns the magnitude of a vector. To calculate the magnitude
we use the sqrf and powf functions.
@return result (float) - returns the total result of the magnitude of a vector.
*/
float Vector2D::magnitude()
{
	float result;
	result = sqrtf((powf(getX(), 2)) + (powf(getY(), 2)));
	return result;
}

/**
Calculates then returns a normilised vector. To calculate the normal of a vector
we first have to find the magnitude, Then we have to divide the positions by the
magnitude.
@retutn result (Vector2D) - returns the result as a two dimensional vector.
*/
Vector2D Vector2D::normalise()
{
	float mag;
	mag = this->magnitude();

	float totalResultX;
	float totalResultY;
	totalResultX = m_x / mag;
	totalResultY = m_y / mag;

	this->setX(totalResultX);
	this->setY(totalResultY);
	return (*this);
}

/**
Calculates the dot product of a vector, then returns the calculates value. To calculate
the dot product, we multply the x and y position of two vectors together then add the
values together.
@param vector (Vector2D &) - address or refernce to another vector.
@returns result (float) - returns the dot product of a vector.
*/
float Vector2D::dotProduct(Vector2D &vector)
{
	float result;
	result = (getX() * vector.getX()) + (getY() * vector.getY());
	return result;
}

/**
Performs + operations with vectors. This will add two Vector2D type objects together.
@param vector (Vector2D &) - address or reference to another vector.
@return result (Vector2D) - returns the total sum of vectors.
*/
Vector2D Vector2D::operator+(Vector2D &vector)
{
	float totalSumX;
	float totalSumY;
	totalSumX = getX() + vector.getX();
	totalSumY = getY() + vector.getY();

	Vector2D result;
	result.setX(totalSumX);
	result.setY(totalSumY);
	return result;
}

/**
Performs the + operations using floats. This will add a Vector2D type to a float type.
@param scalar (float) - The value that will be added onto both coordinates of vector.
@return result (Vector2D) - returns the total sum of the vector.
*/
Vector2D Vector2D::operator+(float scalar)
{
	float totalSumX;
	float totalSumY;
	totalSumX = getX() + scalar;
	totalSumY = getY() + scalar;

	Vector2D result;
	result.setX(totalSumX);
	result.setY(totalSumY);
	return result;
}

/**
Performs the - operations with vectors. This will subtract a Vector2D from a Vector2D type.
@param vector (Vector2D &) - address or reference to anothe vector.
@return result (Vector2D) - return the total sum of subtracted vectors.
*/
Vector2D Vector2D::operator-(Vector2D &vector)
{
	float totalSumX;
	float totalSumY;
	totalSumX = getX() - vector.getX();
	totalSumY = getY() - vector.getY();

	Vector2D result;
	result.setX(totalSumX);
	result.setY(totalSumY);
	return result;
}

/**
Performs the - operation using both Vector2D and float types. This will subtract an Vector2D
type from a float type.
@param scalar (float) - the value that will be used to subtract from vector.
@return vector (Vector2D) - returns the total sum subtracted from float and vector.
*/
Vector2D Vector2D::operator-(float scalar)
{
	float totalSumX;
	float totalSumY;
	totalSumX = getX() - scalar;
	totalSumY = getY() - scalar;

	Vector2D result;
	result.setX(totalSumX);
	result.setY(totalSumY);
	return result;
}

/**
Performs the / operations using Vector2D types. This will divide two Vector2D types from
each other.
@param vector (Vector2D &) - address or reference of another vector.
@return result (Vector2D) - returns the total sum of the divided vector.
*/
Vector2D Vector2D::operator/(Vector2D &vector)
{
	float totalSumX;
	float totalSumY;
	totalSumX = getX() / vector.getX();
	totalSumY = getY() / vector.getY();

	Vector2D result;
	result.setX(totalSumX);
	result.setY(totalSumY);
	return result;
}

/**
Performs the / operations usinf Vector2D and float types. This will divide a Vector2D type
from a float type.
@param scalar (float) - the value that will be used to divide from vectors.
@return result (Vector2D) - returns the total result of the divided vector.
*/
Vector2D Vector2D::operator/(float scalar)
{
	float totalSumX;
	float totalSumY;
	totalSumX = getX() / scalar;
	totalSumY = getY() / scalar;

	Vector2D result;
	result.setX(totalSumX);
	result.setY(totalSumY);
	return result;
}

/**
Performs the * operations using Vector2D types. This will multiply two Vector2D types
together.
@param vector (Vector2D &) - address or reference to another Vector2D.
@return result (Vector2D) - returns total sum of multplied vectors.
*/
Vector2D Vector2D::operator*(Vector2D &vector)
{
	float totalSumX;
	float totalSumY;
	totalSumX = getX() * vector.getX();
	totalSumY = getY() * vector.getY();

	Vector2D result;
	result.setX(totalSumX);
	result.setY(totalSumY);
	return result;
}

/**
Performs the * operations using both Vector2D ant float types. This multiplies a Vector2D
type to a float type.
@param scalar (float) - the value the vector will be multiplie with.
@return result (Vector2D) - total sum of the multiplied vector.
*/
Vector2D Vector2D::operator*(float scalar)
{
	float totalSumX;
	float totalSumY;
	totalSumX = getX() * scalar;
	totalSumY = getY() * scalar;

	Vector2D result;
	result.setX(totalSumX);
	result.setY(totalSumY);
	return result;
}

/**
Performs the = operation. This will assign a Vector2D type onto another Vector2D type.
@param vector (Vector2D &) - address or reference to another vector.
@return this (Vector2D) - returns the assigned vector.
*/
Vector2D Vector2D::operator=(Vector2D &vector)
{
	float totalSumX;
	float totalSumY;
	totalSumX = vector.m_x;
	totalSumY = vector.m_y;

	this->setX(totalSumX);
	this->setY(totalSumY);
	return (*this);
}

/**
Performs the = operation. This will assign a float type onto a Vector2D type. Returns the
assigned vector.
@param scalar (float) - The value that will be assigned to a vector.
@return this (Vector2D) - returns the vector.
*/
Vector2D Vector2D::operator=(float scalar)
{
	this->setX(scalar);
	this->setY(scalar);
	return (*this);
}

/**
Performs the += operation. This will add and assign the added vector to itself.
@param vector (Vector2D &) address or reference to another vector.
@return this (Vector2D) returns the result.
*/
Vector2D Vector2D::operator+=(Vector2D &vector)
{
	this->setX(getX() + vector.getX());
	this->setY(getY() + vector.getY());
	return (*this);
}

/**
Performs the += operation using Vectors and floats, then returns the total sun of the
vector. This adds a scalar onto the current vector, then the vector assigns the total
sum to itself.
@param scalar (float) - This value will be added on to the vector.
@return this (Vector2D) - returns the assigned total sum.
*/
Vector2D Vector2D::operator+=(float scalar)
{
	this->setX(getX() + scalar);
	this->setY(getY() + scalar);
	return (*this);
}

/**
Performs the -= operation using Vector2D types, then returns the calculate value. This will
subtract from a current vector and assign the calculated value onto itself.
@param vector (Vector2D &) - address or reference to another vector.
@return this (Vector2D) - returns the claculated value assigned to this vector.
*/
Vector2D Vector2D::operator-=(Vector2D &vector)
{
	this->setX(getX() - vector.getX());
	this->setY(getY() - vector.getY());
	return (*this);
}

/**
Performs the -= operation using Vector2D anf float types, then returning the values as a
vector.
@param scalar (float) - This vale will be subtract assigned onto the vector.
@return this (Vector2D) - returns the vector.
*/
Vector2D Vector2D::operator-=(float scalar)
{
	this->setX(getX() - scalar);
	this->setY(getY() - scalar);
	return (*this);
}

/**
Performs *= operations usinf Vector2D types. This will multiply two vectors together, then
it will assign the total some of these multiplies vectors to itself.
@param vector (Vector2D &) - address or reference to another vector.
@return this (Vector2D) - returns the assigned value.
*/
Vector2D Vector2D::operator*=(Vector2D &vector)
{
	this->setX(getX() * vector.getX());
	this->setY(getY() * vector.getY());
	return (*this);
}

/**
Performs the *= operation using Vector2D and floats. This will multply a float to a vector.
The vector will the assign the multplied value to itself.
@param scalar (float) - The value that will be multiplied with the vector.
@return this (Vector2D) - returns the assigned value.
*/
Vector2D Vector2D::operator*=(float scalar)
{
	this->setX(getX() * scalar);
	this->setY(getY() * scalar);
	return (*this);
}

/**
Performs the /= operation. This will divide a vector from another vector. Then it will assign
the calculated value to itself.
@param vector (Vector2D &) - address or reference to another vector.
@return this (Vector2D) - returns the calculated value.
*/
Vector2D Vector2D::operator/=(Vector2D &vector)
{
	this->setX(getX() / vector.getX());
	this->setY(getY() / vector.getY());
	return (*this);
}

/**
Performs the /= operation. This will divide a vector by a scalar. The vaule returned
will be assigned to the vector.
@param scalar (float) - The value that will be divide by the vector.
@return this (Vector2D) - returns claculated result.
*/
Vector2D Vector2D::operator/=(float scalar)
{
	this->setX(getX() / scalar);
	this->setY(getY() / scalar);
	return (*this);
}

/**
Performs the == operation. This will check for equality between two vectors.
@param vector (Vector2D &) - address or reference to another vector.
@return true (bool) - If the vector is equal.
@return false (bool) - If the vector is not equal.
*/
bool Vector2D::operator==(Vector2D &vector)
{
	if (getX() == vector.getX() &&
		getY() == vector.getY())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
Performs the != operation to do a check between two vectors. This will check if two Vector2D
type objects are not equal to each other.
@param vector (Vector2D &) - address or reference to another vector.
@return true (bool) - If the vector is not equal.
@return false (bool) - If the vector is equal.
*/
bool Vector2D::operator!=(Vector2D &vector)
{
	if (getX() != vector.getX() && getY() != vector.getY() ||
		getX() != vector.getX() && getY() == vector.getY() ||
		getX() == vector.getX() && getY() != vector.getY())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
Performs the > operation using Vector2D objects. This will check if a Vector2D type
object is greater than another
@param vector (Vector2D &) - address or reference to another vector.
@return true (bool) - The vector is greater than the other.
@return false (bool) - The vector is less than the other.
*/
bool Vector2D::operator>(Vector2D &vector)
{
	if (getX() > vector.getX() &&
		getY() > vector.getY())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
Performs the < operation using Vector2D objects. This will check if a Vector2D type
object is less than another
@param vector (Vector2D &) - address or reference to another vector.
@return true (bool) - The vector is less than the other.
@return false (bool) - The vector is greater than the other.
*/
bool Vector2D::operator<(Vector2D &vector)
{
	if (getX() < vector.getX() &&
		getY() < vector.getY())
	{
		return true;
	}
	else
	{
		return false;
	}
}