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

		static cgmath::mat3 inverse(const cgmath::mat3& m)
		{
			const cgmath::vec3& a = m[0];
			const cgmath::vec3& b = m[1];
			const cgmath::vec3& c = m[2];

			cgmath::vec3 r0 = cgmath::vec3::cross(b, c);
			cgmath::vec3 r1 = cgmath::vec3::cross(c, a);
			cgmath::vec3 r2 = cgmath::vec3::cross(a, b);

			float invDet = 1.0f / cgmath::vec3::dot(a, r0);

			r0 *= invDet;
			r1 *= invDet;
			r2 *= invDet;

			mat3 inv;
			inv[0][0] = r0.x; inv[1][0] = r0.y; inv[2][0] = r0.z;
			inv[0][1] = r1.x; inv[1][1] = r1.y; inv[2][1] = r1.z;
			inv[0][2] = r2.x; inv[1][2] = r2.y; inv[2][2] = r2.z;

			return inv;
		}

		static cgmath::mat3 transpose(const cgmath::mat3& m)
		{
			const cgmath::vec3& a = m[0];
			const cgmath::vec3& b = m[1];
			const cgmath::vec3& c = m[2];

			return mat3(cgmath::vec3(a.x, b.x, c.x), cgmath::vec3(a.y, b.y, c.y), cgmath::vec3(a.z, b.z, c.z));
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