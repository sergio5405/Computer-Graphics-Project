#include "cgmath.h"
#include "metaball.h"
#include "vec3.h"
#include <iostream>
#include <limits>

const float OFFSET = 0;

metaball::metaball(cgmath::vec3 center, const float radius, cgmath::vec3 speed, const cgmath::vec3 color) :
	center(center), radius(radius), speed(speed), color(color) {}

float metaball::influence(cgmath::vec3 vertex) {
	return fmin(radius / (center - vertex).magnitude(), 1);
}


void metaball::move(float dt, float coordinateEdge) {
	coordinateEdge -= 1.0f;
	center += speed * 3;

	if (abs(center.x) > (abs(coordinateEdge) - radius)) {
		speed.x *= -1;

		if (center.x > (coordinateEdge - radius))
			center.x = coordinateEdge - radius - OFFSET;
		else 
			center.x = -coordinateEdge + radius + OFFSET;
	}

	if (abs(center.y) > (abs(coordinateEdge) - radius)) {
		speed.y *= -1;

		if (center.y > (coordinateEdge - radius))
			center.y = coordinateEdge - radius - OFFSET;
		else
			center.y = -coordinateEdge + radius + OFFSET;
	}

	if (abs(center.z) > (abs(coordinateEdge) - radius)) {
		speed.z *= -1;

		if (center.z > (coordinateEdge - radius))
			center.z = coordinateEdge - radius - OFFSET;
		else
			center.z= -coordinateEdge + radius + OFFSET;
	}
}

