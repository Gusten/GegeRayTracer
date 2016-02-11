#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Intersectable.h"
#include <vector>

class Raytracer
{
public:
	Raytracer();

	void tracePrimaryRays(int width, int height);
private:
	// Early implementation will use a simple list with all primitives that can be checked for intersection
	// TODO:: Implement some kind of spatial subdivision for acceleration. (Surface area heuristics, Kd-trees)
	std::vector<Intersectable> allPrimitives;
};

#endif // !RAYTRACER_H
