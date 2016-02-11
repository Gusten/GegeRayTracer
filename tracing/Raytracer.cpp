#include "Raytracer.h"
#include "Ray.h"
#include "../mathutils/Vector3.h"

Raytracer::Raytracer() {

}

// Trace all primary rays through the image plane with given width and height
void Raytracer::tracePrimaryRays(int width, int height) {

	Vector3 currDir;

	// For each pixel in the image plane, shoot a ray and store the color returned.
	for (int i = 0; i < width; i++)
	{
		for (int i = 0; i < height; i++)
		{
			//TODO: Calculate correct tracing direction
			currDir = Vector3();
			Ray newRay = Ray(currDir);

			// Calculate intersections with objects in the scene
		}
	}


}