#ifndef RAY_H
#define RAY_H

// This class defines a ray in the form of R(t) = R_o + R_d * t
// where R_o is the ray origin(vector), R_d is the normalized
// ray direction vector and t is the distance variable.

#include "..\mathutils\vector3.h"

class ray
{
public:
	vector3 origin;
	vector3 direction;

	ray(const vector3& o, const vector3& d);

};

#endif // !RAY_H
