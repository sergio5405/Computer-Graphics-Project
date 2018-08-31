#pragma once
#include <cmath>
#include <iostream>

#include "vec3.h"

namespace cgmath {
	class mat3 {
	private:
		vec3 n[3];

	public:
		mat3();
		mat3(float diagonal);
		mat3(const vec3& a, const vec3& b, const vec3& c);
		vec3& operator[](int column);
		const vec3& operator[] (int column) const;
		bool operator==(const mat3& m) const;

		static float determinant(const mat3& m) {
			return m[0][0] * ((m[1][1] * m[2][2]) - (m[1][2] * m[2][1]))
				- m[0][1] * ((m[1][0] * m[2][2]) - (m[1][2] * m[2][0]))
				- m[0][2] * ((m[1][0] * m[2][1]) - (m[1][1] * m[2][0]));
		}

		static mat3 inverse(const mat3& m) {
			mat3 mt = transpose(m);

			float det1 = mt[1][1] * mt[2][2] - mt[1][2] * mt[2][1];
			float det2 = mt[1][0] * mt[2][2] - mt[1][2] * mt[2][0];
			float det3 = mt[1][0] * mt[2][1] - mt[1][1] * mt[2][0];

			float det4 = mt[0][1] * mt[2][2] - mt[0][2] * mt[2][1];
			float det5 = mt[0][0] * mt[2][2] - mt[0][2] * mt[2][0];
			float det6 = mt[0][0] * mt[2][1] - mt[0][1] * mt[2][0];

			float det7 = mt[0][1] * mt[1][2] - mt[0][2] * mt[1][1];
			float det8 = mt[0][0] * mt[1][2] - mt[0][2] * mt[2][0];
			float det9 = mt[0][0] * mt[1][1] - mt[0][1] * mt[2][0];

			det2 *= -1;
			det4 *= -1;
			det6 *= -1;
			det8 *= -1;


			vec3 a = vec3(det1, det4, det7);
			vec3 b = vec3(det2, det5, det8);
			vec3 c = vec3(det4, det6, det9);

			a *= 1 / determinant(m);
			b *= 1 / determinant(m);
			c *= 1 / determinant(m);

			return mat3(a, b, c);
		}

		static mat3 transpose(const mat3& m) {
			mat3 ret;
			ret = mat3();
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					ret[i][j] = m[j][i];
			return ret;
		}

		friend std::ostream& operator<<(std::ostream& os, const mat3& m) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					os << m[i][j] << " ";
				os << "\n";
			}

			return os;
		}
	};

	inline vec3 operator*(const mat3& m, const vec3& v){
		return vec3(m[0][0] * v[0] + m[0][1 ] *v[1] + m[0][2] * v[2],
					m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2],
					m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2]);
	}

	inline mat3 operator*(const mat3& m1, const mat3& m2) {
		vec3 a = vec3(	m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0] + m1[0][2] * m2[2][0],
						m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0] + m1[1][2] * m2[2][0], 
						m1[2][0] * m2[0][0] + m1[2][1] * m2[1][0] + m1[2][2] * m2[2][0]);

		vec3 b = vec3(	m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1] + m1[0][2] * m2[2][1],
						m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1] + m1[1][2] * m2[2][1],
						m1[2][0] * m2[0][1] + m1[2][1] * m2[1][1] + m1[2][2] * m2[2][1]);

		vec3 c = vec3(	m1[0][0] * m2[0][2] + m1[0][1] * m2[1][2] + m1[0][2] * m2[2][2],
						m1[1][0] * m2[0][2] + m1[1][1] * m2[1][2] + m1[1][2] * m2[2][2],
						m1[2][0] * m2[0][2] + m1[2][1] * m2[1][2] + m1[2][2] * m2[2][2]);
		return mat3(a,b,c);
	}
}