#include "vec3.h"

cgmath::vec3::vec3() : x(0.0f), y(0.0f), z(0.0) {}
cgmath::vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}

float& cgmath::vec3::operator[](int i) {
	if (i == 0)
		return x;
	if (i == 1)
		return y;
	if (i == 2)
		return z;
}

const float& cgmath::vec3::operator[] (int i) const {
	if (i == 0)
		return x;
	if (i == 1)
		return y;
	if (i == 2)
		return z;
}

cgmath::vec3& cgmath::vec3::operator*=(float s) {
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

cgmath::vec3& cgmath::vec3::operator/=(float s) {
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

cgmath::vec3& cgmath::vec3::operator+=(const vec3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

cgmath::vec3& cgmath::vec3::operator-=(const vec3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

bool cgmath::vec3::operator==(const vec3& v) const {
	return (v.x == x && v.y == y && v.z == z);
}

float cgmath::vec3::magnitude() const {
	return sqrt(x*x + y * y + z * z);
}

void cgmath::vec3::normalize() {
	x /= magnitude();
	y /= magnitude();
	z /= magnitude();
}