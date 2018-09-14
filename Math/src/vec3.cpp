#include "vec3.h"

cgmath::vec3::vec3() : x(0.0f), y(0.0f), z(0.0) {}
cgmath::vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}



float cgmath::vec3::magnitude() const {
	return sqrt(x*x + y * y + z * z);
}

void cgmath::vec3::normalize() {
	x /= magnitude();
	y /= magnitude();
	z /= magnitude();
}

float cgmath::vec3::magnitude(const cgmath::vec3& v){
	return v.magnitude();
}

cgmath::vec3 cgmath::vec3::normalize(const cgmath::vec3& v){
	return v / v.magnitude();
}

float cgmath::vec3::dot(const cgmath::vec3& a, const cgmath::vec3& b){
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

cgmath::vec3 cgmath::vec3::cross(const cgmath::vec3& a, const cgmath::vec3& b){
	return cgmath::vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

float& cgmath::vec3::operator[](int i){
	return (&x)[i];
}

const float& cgmath::vec3::operator[](int i) const{
	return (&x)[i];
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

