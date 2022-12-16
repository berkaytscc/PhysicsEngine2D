#include "Body.h"
#include <iostream>

Body::Body(const Shape &shape, float x, float y, float mass)
{
	this->shape = shape.Clone();
	this->position = Vector2D(x, y);
	this->velocity = Vector2D(0, 0);
	this->acceleration = Vector2D(0, 0);
	this->rotation = 0.0f;
	this->angularVelocity = 0.0f;
	this->angularAcceleration = 0.0f;
	this->sumForces = Vector2D(0, 0);
	this->sumTorque = 0.0f;;
	this->restitution = 0.6f;
	this->friction = 0.7f;
	this->mass = mass;

	if (mass != 0.0f)
		this->invMass = 1.0f / mass;
	else
		this->invMass = 0.0f;

	inertia = shape.GetMomentOfInertia() * mass;

	if (inertia != 0.0f)
		this->invInertia = 1.0f / inertia;
	else
		this->invInertia = 0.0f;

	//this->shape->UpdateVertices(rotation, position); TODO: Will be added later
	std::cout << "Body constructor" << "\n";
}


Body::~Body()
{
	SDL_DestroyTexture(this->texture);
	std::cout << "Body destructor" << "\n";
}

bool Body::isStatic() const
{
	const float epsilon = 0.005f;
	return fabs(this->invMass - 0.0f) < epsilon; // minus zero 
}


void Body::AddForce(const Vector2D force)
{
	sumForces += force;
}

void Body::AddTorque(float torque)
{
	sumTorque += torque;
}

void Body::ClearForce()
{
	sumForces = Vector2D(0.0f, 0.0f);
}

void Body::ClearTorque()
{
	sumTorque = 0.0f;
}

void Body::IntegrateForces(const float dt)
{
	if (isStatic())
		return;

	acceleration = sumForces * invMass;

	velocity += acceleration * dt;

	angularAcceleration = sumTorque * invInertia;

	angularVelocity += angularAcceleration * dt;
	
	ClearForce();
	ClearTorque();

}

void Body::IntegrateVelocities(const float dt)
{
	if (isStatic())
		return;

	position += velocity * dt;

	rotation += angularVelocity * dt;

	//TODO: ADD update vertices method for the shape object
}
