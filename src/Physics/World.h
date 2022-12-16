#ifndef WORLD_H
#define WORLD_H

#include "Body.h"
#include <vector>
#include <iostream>
#include "Constants.h"

class World {
	private:
		float gravity = 9.8f;
		std::vector<Body*> bodies;
		//TODO: add constraints later

		std::vector<Vector2D> forces;
		std::vector<float> torques;

	public:
		World(float gravity);
		~World();

		void AddBody(Body* body);
		std::vector<Body*> GetBodies();
		
		
		//TODO: add constraint later

		void AddForce(const Vector2D force);
		void AddTorque(float torque);

		void Update(float dt);

		//TODO: add collision later --> CheckCollisions();

};

#endif // !WORLD_H


