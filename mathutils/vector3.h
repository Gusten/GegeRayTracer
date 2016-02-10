#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>

class vector3
{
public:
	float x;
	float y;
	float z;

	vector3();
	vector3(const vector3& a);
	vector3(float nx, float ny, float nz);

	void normalize();

	std::string to_string();

	// Overload appropriate basic operators
	vector3 operator+(const vector3& b);
	vector3 operator-(const vector3& b);

	// Useful vector functions
	float dotProduct(const vector3& b);
	vector3 crossProduct(const vector3& b);
};

#endif // !VECTOR3_H