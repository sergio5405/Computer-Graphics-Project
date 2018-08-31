#include "mat4.h"

cgmath::mat4::mat4() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			n[i][j] = 0;
}

cgmath::mat4::mat4(float diagonal) {
	for (int i = 0; i < 3; i++)
		n[i][i] = diagonal;
}

cgmath::mat4::mat4(const vec4& a, const vec4& b, const vec4& c, const vec4& d) {
	n[0] = a;
	n[1] = b;
	n[2] = c;
	n[3] = d;
}

cgmath::vec4& cgmath::mat4::operator[](int column) {
	return n[column];
}

const cgmath::vec4& cgmath::mat4::operator[] (int column) const {
	return n[column];
}

bool cgmath::mat4::operator==(const mat4& m) const {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (n[i][j] != m[i][j])
				return false;
	return true;
}