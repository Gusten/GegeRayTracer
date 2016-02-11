#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>

class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3();
	Vector3(const Vector3& a);
	Vector3(float nx, float ny, float nz);

	void normalize();

	std::string to_string();

	// Overload appropriate basic operators
	Vector3 operator+(const Vector3& b);
	Vector3 operator-(const Vector3& b);

	// Useful vector functions
	float dotProduct(const Vector3& b);
	Vector3 crossProduct(const Vector3& b);
};

#endif // !VECTOR3_H
