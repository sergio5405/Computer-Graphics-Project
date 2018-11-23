#include "mat3.h"

cgmath::mat3::mat3() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			n[i][j] = 0;
}

cgmath::mat3::mat3(float diagonal) {
	for (int i = 0; i < 3; i++)
		n[i][i] = diagonal;
}

cgmath::mat3::mat3(const vec3& a, const vec3& b, const vec3& c) {
	n[0] = a;
	n[1] = b;
	n[2] = c;
}

cgmath::vec3& cgmath::mat3::operator[](int column) {
	return n[column];
}

const cgmath::vec3& cgmath::mat3::operator[] (int column) const {
	return n[column];
}

bool cgmath::mat3::operator==(const mat3& m) const {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (n[i][j] != m[i][j])
				return false;
	return true;
}