#include "Vector2D.h"
#include <math.h>

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

Vector2D Vector2D::Rotate(float angle) {
	Vector2D rotatedVector; 
	rotatedVector.x = x * cosf(angle) - y * sinf(angle);
	rotatedVector.y = x * sinf(angle) + y * cosf(angle);
	return rotatedVector;
}

float Vector2D::Magnitude() {
	return sqrtf(this->x * this->x + this->y * this->y);
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

void Vector2D::Normalize() {
	float length = this->Magnitude();
	this->x /= length;
	this->y /= length;
	//TODO: set the vector to 0 if it's too small to be normalized
	
}

Vector2D Vector2D::normalized()
{
	Vector2D result = Vector2D(this->x, this->y);
	result.Normalize();
	return result;
}

Vector2D Vector2D::UnitVector() {
	//TODO: Write unit vector codeW
}