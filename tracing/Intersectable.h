#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

#include "Ray.h"
#include "Intersection.h"

class Intersectable
{
public:
	virtual bool intersect(Ray ray, Intersection isect) = 0;
};

#endif // !INTERSECTABLE_H
