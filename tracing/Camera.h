#ifndef CAMERA_H
#define CAMERA_H

#include "../mathutils/Vector3.h"

class Camera
{
public:
	Vector3 center;
	Vector3 up;
	Vector3 forward;
	Vector3 right;
	float hfov;
	float vfov;
};

#endif // !CAMERA_H
