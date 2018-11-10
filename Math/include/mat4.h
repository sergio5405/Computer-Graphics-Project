#pragma once

#include <ostream>
#include "vec4.h"
#include "vec3.h"

namespace cgmath
{
	class mat4
	{
	private:
		float n[4][4];

	public:
		mat4();
		mat4(float diagonal);
		mat4(const cgmath::vec4& a, const cgmath::vec4& b, const cgmath::vec4& c, const cgmath::vec4& d);

		cgmath::vec4& operator[](int column);
		const cgmath::vec4& operator[](int column) const;

		bool operator==(const mat4& m) const;

		static mat4 inverse(const mat4& m);
		static mat4 rotateMatrix(float xDeg, float yDeg, float zDeg);

		friend std::ostream& operator<<(std::ostream& os, const mat4& m){
			os << m[0][0] << " " << m[1][0] << " " << m[2][0] << " " << m[3][0] << std::endl;
			os << m[0][1] << " " << m[1][1] << " " << m[2][1] << " " << m[3][1] << std::endl;
			os << m[0][2] << " " << m[1][2] << " " << m[2][2] << " " << m[3][2] << std::endl;
			os << m[0][3] << " " << m[1][3] << " " << m[2][3] << " " << m[3][3];
			return os;
		}
	};

	inline cgmath::vec4 operator*(const mat4& m, const cgmath::vec4& v)
	{
		return m[0] * v.x + m[1] * v.y + m[2] * v.z + m[3] * v.w;
	}

	inline mat4 operator*(const mat4& m1, const mat4& m2)
	{
		cgmath::vec4 a(m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3]);

		cgmath::vec4 b(m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3]);

		cgmath::vec4 c(m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3],
			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3]);

		cgmath::vec4 d(m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2] + m1[3][0] * m2[3][3],
			m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2] + m1[3][1] * m2[3][3],
			m1[0][2] * m2[3][0] + m1[1][2] * m2[3][1] + m1[2][2] * m2[3][2] + m1[3][2] * m2[3][3],
			m1[0][3] * m2[3][0] + m1[1][3] * m2[3][1] + m1[2][3] * m2[3][2] + m1[3][3] * m2[3][3]);

		return mat4(a, b, c, d);
	}
}
