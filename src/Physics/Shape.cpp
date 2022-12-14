#include "Shape.h"
#include <iostream>

#pragma region Circle

CircleShape::CircleShape(float radius) {
	this->radius = radius;
	std::cout << "Circle constructor" << "\n";
}

CircleShape::~CircleShape() {
	std::cout << "Circle destructor" << "\n";
}

ShapeType CircleShape::GetType() const {
	return CIRCLE;
}

Shape* CircleShape::Clone() const {
	return new CircleShape(radius);
}

void CircleShape::UpdateVertices(float angle, const Vector2D position) {
	return;
}

float CircleShape::GetMomentOfInertia() const {
	return 0.5 * (radius * radius);
}

#pragma endregion

#pragma region Polygon
PolygonShape::PolygonShape(const std::vector<Vector2D> vertices) {
	//TODO: will be added later
	std::cout << "PolygonShape constructor" << "\n";
}

PolygonShape::~PolygonShape() {
	std::cout << "PolygonShape destructor" << "\n";
}
ShapeType PolygonShape::GetType() const
{
	return POLYGON;
}
Shape* PolygonShape::Clone() const
{
	//TODO: return PolygonShape(localVertices)
	return new PolygonShape();
}
void PolygonShape::UpdateVertices(float angle, const Vector2D position)
{
	//TODO: will be added later
}
float PolygonShape::GetMomentOfInertia() const
{
	//FIXME: temp 5000
	return 5000;
}
#pragma endregion

#pragma region Box
BoxShape::BoxShape(float width, float height)
{
	this->width = width;
	this->height = height;

	//TODO: local and world vertices
}

BoxShape::~BoxShape()
{
	//TODO: ...
}

ShapeType BoxShape::GetType() const
{
	return BOX;
}

Shape* BoxShape::Clone() const
{
	return new BoxShape(width,height);
}

float BoxShape::GetMomentOfInertia() const
{
	return (0.083333) * (width * width + height * height);
}
#pragma endregion
