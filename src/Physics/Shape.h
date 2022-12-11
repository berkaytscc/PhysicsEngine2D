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
	virtual ShapeType GetType() const = 0;		// = 0 means 'pure virtual' function --> GetType() needs to be defined in every shape object individually
	virtual Shape* Clone() const = 0;			
	virtual void UpdateVertices(float angle, const Vector2D position) = 0;
	virtual float GetMomentOfInertia() const = 0;
};

struct CircleShape: public Shape
{
	float radius;

	CircleShape(const float radius);
	virtual ~CircleShape();
	ShapeType GetType() const override;
	Shape* Clone() const override;
	void UpdateVertices(float angle, const Vector2D position) override;
	float GetMomentOfInertia() const override;
};

struct PolygonShape: public Shape
{
	std::vector<Vector2D> localVertices;
	std::vector<Vector2D> worldVertices;

	PolygonShape() = default;
	PolygonShape(const std::vector<Vector2D> vertices);
	virtual ~PolygonShape();
	ShapeType GetType() const override;
	Shape* Clone() const override;
	void UpdateVertices(float angle, const Vector2D position) override;
	float GetMomentOfInertia() const override;

	//TODO: Add collision related functions later
};

struct BoxShape: public PolygonShape
{
	float width;
	float height;

	BoxShape(float width, float height);
	virtual ~BoxShape();
	ShapeType GetType() const override;
	Shape* Clone() const override;
	float GetMomentOfInertia() const override;
};


#endif // !SHAPE_H

