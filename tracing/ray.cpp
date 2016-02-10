#include "ray.h"

ray::ray(const vector3& o, const vector3& d) {
	origin = vector3(o);
	direction = vector3(d);
	// We want our direction vector to be normalized
	direction.normalize();
}