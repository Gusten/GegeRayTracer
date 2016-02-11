#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Intersectable.h"
#include "Intersection.h"

class Triangle : public Intersectable
{
public:
	// A triangle is made up of 3 points in space; A, B and C.
	Vector3 pointA;
	Vector3 pointB;
	Vector3 pointC;

	Triangle(const Vector3& a, const Vector3& b, const Vector3& c);

	bool intersect(Ray ray, Intersection isect);
};

#endif // !TRIANGLE_H
