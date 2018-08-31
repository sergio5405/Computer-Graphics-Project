#include "vec4.h"

cgmath::vec4::vec4() : x(0.0f), y(0.0f), z(0.0), w(0.0) {}
cgmath::vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

float& cgmath::vec4::operator[](int i) {
	if (i == 0)
		return x;
	if (i == 1)
		return y;
	if (i == 2)
		return z;
	if (i == 3)
		return w;
}

const float& cgmath::vec4::operator[] (int i) const {
	if (i == 0)
		return x;
	if (i == 1)
		return y;
	if (i == 2)
		return z;
	if (i == 3)
		return w;
}

cgmath::vec4& cgmath::vec4::operator*=(float s) {
	x *= s;
	y *= s;
	z *= s;
	w *= s;
	return *this;
}

cgmath::vec4& cgmath::vec4::operator/=(float s) {
	x /= s;
	y /= s;
	z /= s;
	w /= s;
	return *this;
}

cgmath::vec4& cgmath::vec4::operator+=(const vec4& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

cgmath::vec4& cgmath::vec4::operator-=(const vec4& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

bool cgmath::vec4::operator==(const vec4& v) const {
	return (v.x == x && v.y == y && v.z == z && v.w == w);
}
