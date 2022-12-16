#include "World.h"

World::World(float gravity)
{
	this->gravity = gravity;
	std::cout << "World constructor" << "\n";
}

World::~World()
{
	for (Body* body : this->bodies) {
		delete body;
	}
	//TODO: delete constraints later

	std::cout << "World destructor" << "\n";
}

void World::AddBody(Body* body)
{
	bodies.push_back(body);
}

std::vector<Body*> World::GetBodies()
{
	return bodies;
}

void World::AddForce(const Vector2D force)
{
	forces.push_back(force);
}

void World::AddTorque(float torque)
{
	torques.push_back(torque);
}

void World::Update(float dt)
{
	for (Body* body: bodies)
	{
		Vector2D weight = Vector2D(0.0f, body->mass * gravity * PIXEL_PER_METER);
		body->AddForce(weight);

		for (Vector2D force : forces)
		{
			body->AddForce(force);
		}

		for (float torque : torques)
		{
			body->AddTorque(torque);
		}
	}

	for (Body* body : bodies)
	{
		body->IntegrateForces(dt);
	}

	// add collision later

	for (Body* body : bodies)
	{
		body->IntegrateVelocities(dt);
	}
}
