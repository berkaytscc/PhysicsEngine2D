#ifndef VEC2_H
#define VEC2_H

/// <summary>
/// Representation of 2D vectors and points.
/// This structure is used in some places to represent 2D positions and vectors
/// </summary>
struct Vector2D {
	//
	// Summary:
	//     X component of the vector.
	float x;
	//
	// Summary:
	//     Y component of the vector.
	float y;

	//HACK:	This implementation creates proper Vector2D but default constructor is missing.
	//		Search for that can it be done any better. Also the usage of 'const' and 'referance 
	//		parameters' should be implemented when neccessary.
	
	//Vector2D() = default;
	Vector2D(float x, float y);

	~Vector2D() = default;

	void Add(Vector2D v);								// v1.add(v2);
	void Sub(Vector2D v);								// v1.Sub(v2);
	void Scale(float n);								// v1.Scale(x);
	Vector2D Rotate(float angle);						// v1.Rotate(angle);

	float Magnitude();  								// v1.Magnitude();

	float Dot(Vector2D v);								// v1.Dot(v2);
	float Cross(Vector2D v);							// v1.Cross(v2);

	/// <summary>
	/// When a vector is normalized, direction is not changed but its length is 1.0.
	/// Notice that this function will alter the current vector. 
	/// If you want to keep the current vector's properties, use 'normalized' variable.
	/// If vector is too small to be normalized it will be set to zero.
	/// </summary>
	void Normalize();									// v1.Normalize();

	Vector2D normalized();								// v1.normalized();
	Vector2D UnitVector();								// v1.UnitVector();
	Vector2D Perpendicular();							// v1.Perpendicular();
};
#endif
