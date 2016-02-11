#ifndef SPHERE_H
#define SPHERE_H

#include "Intersectable.h"
#include "Intersection.h"

class Sphere : public Intersectable
{
public:
	Vector3 center;
	float radius;

	Sphere(const Vector3& c, const float& r);

	bool intersect(Ray ray, Intersection isect);
};

#endif // !SPHERE_H
