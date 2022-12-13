#ifndef SHAPE_H
#define SHAPE_H

#include "Vector2D.h"
#include <vector>

enum ShapeType
{
	CIRCLE,
	POLYGON,
	BOX
};

struct Shape
{
	~Shape() = default;
	ShapeType GetType();		// = 0 means 'pure virtual' function --> GetType() needs to be defined in every shape object individually
	Shape Clone() const;			
	void UpdateVertices(float angle, const Vector2D position);
	float GetMomentOfInertia() const;
};

struct CircleShape: public Shape
{
	float radius;

	CircleShape(const float radius);
	~CircleShape();
	ShapeType GetType() const;
	Shape Clone() const;
	void UpdateVertices(float angle, const Vector2D position);
	float GetMomentOfInertia() const;
};

struct PolygonShape: public Shape
{
	std::vector<Vector2D> localVertices;
	std::vector<Vector2D> worldVertices;

	PolygonShape() = default;
	PolygonShape(const std::vector<Vector2D> vertices);
	~PolygonShape();
	ShapeType GetType() const;
	Shape Clone() const;
	void UpdateVertices(float angle, const Vector2D position);
	float GetMomentOfInertia() const;

	//TODO: Add collision related functions later
};

struct BoxShape: public PolygonShape
{
	float width;
	float height;

	BoxShape(float width, float height);
	~BoxShape();
	ShapeType GetType() const;
	Shape Clone() const;
	float GetMomentOfInertia() const;
};


#endif // !SHAPE_H

