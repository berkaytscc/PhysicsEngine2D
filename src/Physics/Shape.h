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
	virtual ~Shape() = default;
	virtual ShapeType GetType() const = 0;
	virtual Shape* Clone() const = 0;
	virtual void UpdateVertices(float angle, const Vector2D position) = 0;
	virtual float GetMomentOfInertia() const = 0;

	std::vector<Vector2D> localVertices; // temp
	std::vector<Vector2D> worldVertices;
};

struct CircleShape: public Shape
{
	float radius;

	CircleShape(const float radius);
	virtual ~CircleShape();
	ShapeType GetType() const;
	Shape* Clone() const;
	void UpdateVertices(float angle, const Vector2D position);
	float GetMomentOfInertia() const;
};

struct PolygonShape: public Shape
{
	// vertices should be here

	PolygonShape() = default;
	PolygonShape(const std::vector<Vector2D> vertices);
	virtual ~PolygonShape();
	ShapeType GetType() const;
	Shape* Clone() const;
	void UpdateVertices(float angle, const Vector2D position);
	float GetMomentOfInertia() const;

	//TODO: Add collision related functions later
};

struct BoxShape: public PolygonShape
{
	float width;
	float height;


	BoxShape(float width, float height);
	virtual ~BoxShape();
	ShapeType GetType() const;
	Shape* Clone() const;
	float GetMomentOfInertia() const;
};


#endif // !SHAPE_H

