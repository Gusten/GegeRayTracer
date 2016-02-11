#include "Raytracer.h"
#include "Ray.h"
#include "../mathutils/Vector3.h"
#include "Intersection.h"
#include <iostream>

Raytracer::Raytracer() {

}

// Trace all primary rays through the image plane with given width and height
void Raytracer::tracePrimaryRays(int width, int height) {

	Vector3 currDir;

	// For each pixel in the image plane, shoot a ray and store the color returned.
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			//TODO: Calculate correct tracing direction
			currDir = Vector3();
			Ray eyeRay = Ray(currDir);

			// -- Calculate intersections with objects in the scene
			// Create a new intersection to store appropriate intersect information
			Intersection isect;
			for (int k = 0; k < allPrimitives.size(); k++)
			{
				std::cout << allPrimitives[k].intersect(eyeRay, isect);
			}
		}
	}


}