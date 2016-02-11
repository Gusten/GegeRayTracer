#include "Sphere.h"
#include <math.h>

Sphere::Sphere(const Vector3& c, const float& r) {
	center = Vector3(c);
	radius = float(r);
}

// Check intersection between ray and this sphere.
// The sphere is parameterized as (p - c) * (p - c) - r^2 = 0
// where p is a point on the surface of the sphere and c is its center
// and r its radius.
// To check if an intersection between the ray and the sphere is possible
// we substitute the point p in the sphere equation with our ray equation(R_o + R_d*t)
// and solve for t.
// Remember that R_d is normalized so we can make some nice simplifications
bool Sphere::intersect(Ray ray, Intersection isect) {
	Vector3 diffRaySphere = ray.origin - center;
	float determinant = pow(ray.direction.dotProduct(diffRaySphere), 2) - diffRaySphere.dotProduct(diffRaySphere) + radius * radius;
	if (determinant < 0) {
		// No real solution exists
		return false;
	}
	// This may not be the best implementation but it'll do for now.
	else if (abs(determinant) < 1e-5)  {
		// Exactly one soution exists
		float t = -(ray.direction.dotProduct(diffRaySphere));
		isect.position = ray.origin + (ray.direction * t);
		return true;
	}
	// Two solutions exists, solve for both and check for closest non-negative intersection.
	float sol1 = -(ray.direction.dotProduct(diffRaySphere)) + sqrt(determinant);
	float sol2 = -(ray.direction.dotProduct(diffRaySphere)) - sqrt(determinant);

	if (sol1 < sol2 && sol1 > 0) {
		// Solution 1 is smaller(closer) to the origin of the ray and it's not negative(behind the camera).
		isect.position = ray.origin + (ray.direction * sol1);
		return true;
	}
	if (sol2 > 0) {
		// We know solution 2 is closer and non-negative. So its good.
		isect.position = ray.origin + (ray.direction * sol2);
		return true;
	}
	// If we arrive here without a good value, it means both points are behind the eye(ray origin) so we just
	// disregard the solution and treat the sphere as invisible to the eye.
	return false;
}