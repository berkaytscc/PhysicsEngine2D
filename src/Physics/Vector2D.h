#ifndef VEC2_H
#define VEC2_H

#include <string>

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
	
	Vector2D();
	Vector2D(float x, float y);

	~Vector2D() = default;
																							
	void Add(Vector2D v);								// v1.add(v2);
	void Sub(Vector2D v);								// v1.Sub(v2);
	void Scale(float n);								// v1.Scale(x);
	void Set(float newX, float newY);					// v1.Set(newX, newY);				
	Vector2D Rotate(float angle);						// v1.Rotate(angle);

	float Magnitude();  								// v1.Magnitude();
	float SqrMagnitude();  								// v1.sqrMagnitude();
	/// <summary>
	/// Returns the angle between two vectors in degree
	/// </summary>
	/// <param name="v"> --> first vector</param>
	/// <param name="v2"> --> second vector</param>
	/// <returns></returns>
	
	float Angle(Vector2D v, Vector2D v2);				// Vector2D.Angle(v,v2);

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

	bool isEqual(Vector2D v);							// v1.isEqual(v);		
	
#pragma region Operator Overloading
	//operator = (Vector2D v);							// v1 = v2
	bool operator == (Vector2D v);
	bool operator != (Vector2D v);

	Vector2D operator+ (Vector2D v);					// v1 + v2
	Vector2D operator- (Vector2D v);					// v1 - v2
	Vector2D operator* (float n);						// v1 * n
	Vector2D operator/ (float n);						// v1 / n
	Vector2D operator- ();								// v1 - v2
	
	Vector2D operator+= (Vector2D v);					// v1 += v2
	Vector2D operator-= (Vector2D v);					// v1 -= v2
	Vector2D operator*= (float n);						// v1 *= n
	Vector2D operator/= (float n);						// v1 /= n
#pragma endregion

	std::string ToString();
};
#endif