#include "vec2.h"

cgmath::vec2::vec2() : x(0.0f), y(0.0f) {}
cgmath::vec2::vec2(float x, float y) : x(x), y(y) {}

float& cgmath::vec2::operator[](int i) {
	if (i == 0)
		return x;
	if (i == 1)
		return y;
}

const float& cgmath::vec2::operator[](int i) const {
	if (i == 0)
		return x;
	if (i == 1)
		return y;
}

cgmath::vec2& cgmath::vec2::operator*=(float s) {
	vec2 a = vec2(x*s, y*s);
	return a;
}

cgmath::vec2& cgmath::vec2::operator/=(float s) {
	vec2 a = vec2(x/s, y/s);
	return a;
}

cgmath::vec2& cgmath::vec2::operator+=(const vec2& v) {
	vec2 a = vec2(x+v.x, y+v.y);
	return a;
}

cgmath::vec2& cgmath::vec2::operator-=(const vec2& v) {
	vec2 a = vec2(x - v.x, y - v.y);
	return a;
}

bool cgmath::vec2::operator==(const vec2& v) const {
	return (v.x == x && v.y == y);
}

float cgmath::vec2::magnitude() const {
	return sqrt(x*x + y * y);
}

void cgmath::vec2::normalize() {
	float mag = magnitude();
	x /= mag;
	y /= mag;
}