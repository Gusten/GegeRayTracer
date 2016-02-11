#ifndef RAY_H
#define RAY_H

// This class defines a ray in the form of R(t) = R_o + R_d * t
// where R_o is the ray origin(vector), R_d is the normalized
// ray direction vector and t is the distance variable.

#include "..\mathutils\Vector3.h"

class Ray
{
public:
	Vector3 origin;
	Vector3 direction;

	Ray(const Vector3& d);
	Ray(const Vector3& o, const Vector3& d);

};

#endif // !RAY_H
