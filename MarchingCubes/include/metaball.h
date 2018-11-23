#pragma once

#include "vec3.h"
#include <vector>

class metaball {
public:
	metaball(cgmath::vec3 center, const float radius, cgmath::vec3 speed, const cgmath::vec3 color);
	float influence(cgmath::vec3 vertex);
	void move(float dt, float coordinateEdge);

private:
	cgmath::vec3 center;
	cgmath::vec3 speed;
	cgmath::vec3 color;
	float radius;
};