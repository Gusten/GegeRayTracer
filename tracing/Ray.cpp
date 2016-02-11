#include "Ray.h"

// Shortcut for creating a ray from origin(0,0,0) towards given direction d.
Ray::Ray(const Vector3& d) {
	origin    = Vector3();
	direction = Vector3(d);
}

Ray::Ray(const Vector3& o, const Vector3& d) {
	origin    = Vector3(o);
	direction = Vector3(d);
	// We want our direction vector to be normalized
	direction.normalize();
}
