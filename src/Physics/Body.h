#ifndef BODY_H
#define BODY_H

#include "Vector2D.h"
#include "Shape.h"
#include "SDL.h"


struct Body
{
	//Linear properties
	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;


	//Angular properties
	float rotation;
	float angularVelocity;
	float angularAcceleration;

	Vector2D sumForces;					
	float sumTorque;

	float mass;
	float invMass;
	float inertia;
	float invInertia;

	float restitution;					// TODO: figure out
	float friction;

	Shape shape;

	SDL_Texture* texture = nullptr;

	Body(Shape &shape, float x, float y, float mass);
	~Body();

	bool isStatic() const;

	void AddForce(const Vector2D force);
	void AddTorque(float torque);
	void ClearForce();
	void ClearTorque();

	void IntegrateForces(const float dt);
	void IntegrateVelocities(const float dt);

	// TODO: Add SetTexture method

	/*
	
	Vec2 LocalSpaceToWorldSpace(const Vec2& point) const;
    Vec2 WorldSpaceToLocalSpace(const Vec2& point) const;

    void ApplyImpulseLinear(const Vec2& j);
    void ApplyImpulseAngular(const float j);
    void ApplyImpulseAtPoint(const Vec2& j, const Vec2& r);

    void IntegrateLinear(float dt);
    void IntegrateAngular(float dt);

	*/


};


#endif 


