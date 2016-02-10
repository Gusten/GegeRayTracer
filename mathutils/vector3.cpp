//This class should hold appropriate math and functionality for dealing with 3 dimensional float vectors.

#include "vector3.h"
#include <math.h>

// Initialize the zero vector
vector3::vector3() {
	x = 0;
	y = 0;
	z = 0;
}
// Initialize a vector with x,y,z values copied from given vector a.
vector3::vector3(const vector3& a) {
	this->x = a.x;
	this->y = a.y;
	this->z = a.z;
}
// Initialize a vector with given parameters
vector3::vector3(float nx, float ny, float nz) {
	x = nx;
	y = ny;
	z = nz;
}

// Normalize the vector, also known as setting it's length to 1 unit(unit vector).
void vector3::normalize() {
	float length = sqrt(x*x + y*y + z*z);

	x /= length;
	y /= length;
	z /= length;
}

// Provides a string representation of the vector in the form (x, y, z)
std::string vector3::to_string() {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}

// Operator overloads:
// Adds two vectors to create a new vector in the form a(x,y,z) + b(x,y,z) = c(ax+bx, ay+by, az+bz)
vector3 vector3::operator+(const vector3& b) {
	vector3 c = vector3();

	c.x = this->x + b.x;
	c.y = this->y + b.y;
	c.z = this->z + b.z;

	return c;
}

// Subtract vector b from vector a in the form a(x,y,z) - b(x,y,z) = c(ax-bx, ay-by, az-bz)
vector3 vector3::operator-(const vector3& b) {
	vector3 c = vector3();

	c.x = this->x - b.x;
	c.y = this->y - b.y;
	c.z = this->z - b.z;

	return c;
}

// Vector functions
// Calculates the dot/scalar product of vector a and b in the form of: dotProduct = a.x*b.x + a.y*b.y + a.z*b.z
float vector3::dotProduct(const vector3& b) {
	return (this->x * b.x) + (this->y * b.y) + (this->z * b.z);
}

// Calculates the cross product of vector a and b.
vector3 vector3::crossProduct(const vector3& b) {
	return vector3(this->y * b.z - this->z * b.y,
		           this->z * b.x - this->x * b.z,
		           this->x * b.y - this->y * b.x);
}