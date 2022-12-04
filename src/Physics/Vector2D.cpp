#include "Vector2D.h"
#include <cmath>

#define PI          3.141592653589793238462643383279502884L	// pi

//Vector2D::Vector2D(): x(0.0f), y(0.0f) {}						// default constructure that initializes new Vector2D(0,0)

Vector2D::Vector2D(float x = 0, float y = 0): x(x), y(y) {}		// actual constructure that can be passed paramaters --> new Vector2D(x,y)

void Vector2D::Add(Vector2D v) {
	this->x += v.x;
	this->y += v.y;
}

void Vector2D::Sub(Vector2D v) {
	this->x -= v.x;
	this->y -= v.y;
}

void Vector2D::Scale(float n) {
	this->x *= n;
	this->y *= n;
}

void Vector2D::Set(float newX, float newY)
{
	this->x = newX;
	this->y = newY;
}

Vector2D Vector2D::Rotate(float angle) {
	Vector2D _rotatedVector; 
	_rotatedVector.x = x * cosf(angle) - y * sinf(angle);
	_rotatedVector.y = x * sinf(angle) + y * cosf(angle);
	return _rotatedVector;
}

float Vector2D::Magnitude() {
	return sqrtf(this->x * this->x + this->y * this->y);
}

float Vector2D::SqrMagnitude()
{
	return this->x * this->x + this->y * this->y;
}

float Vector2D::Angle(Vector2D v, Vector2D v2)
{
	float _angle = acosf(v.Dot(v2) / (v.Magnitude() * v2.Magnitude()));
	return _angle * 180 / PI;
}

float Vector2D::Dot(Vector2D v) {
	return (this->x * v.x) + (this->y * v.y);
}

float Vector2D::Cross(Vector2D v) {
	return(this->x * v.y) - (this->y * v.x);
}

Vector2D Vector2D::Perpendicular() {
	return Vector2D(this->y, -this->x);
}

bool Vector2D::isEqual(Vector2D v)
{
	if (this->x == v.x && this->y == v.y)
		return true;
	return false;
}

/// <summary>
/// Normalizes the vector
/// </summary>
void Vector2D::Normalize() {
	float _length = this->Magnitude();
	this->x /= _length;
	this->y /= _length;
	//TODO: set the vector to 0 if it's too small to be normalized
}

/// <summary>
/// Returns a new normalized vector
/// </summary>
/// <returns></returns>
Vector2D Vector2D::normalized()
{
	Vector2D _result = Vector2D(this->x, this->y);
	_result.Normalize();
	return _result;
}

Vector2D Vector2D::UnitVector() {
	//TODO: Write unit vector code
}