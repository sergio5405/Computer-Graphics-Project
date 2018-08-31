#pragma once
#include <cmath>
#include <iostream>

namespace cgmath {
	class vec3 {
	public:
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		vec3();
		vec3(float x, float y, float z);

		float& operator[](int i);
		const float& operator[] (int i) const;

		vec3& operator*=(float s);
		vec3& operator/=(float s);
		vec3& operator+=(const vec3& v);
		vec3& operator-=(const vec3& v);
		bool operator==(const vec3& v) const;
		float magnitude() const;
		void normalize();
	
		static float magnitude(const vec3& v) {
			return sqrt(v.x*v.x + v.y*v.y + v.z * v.z);
		}

		static vec3 normalize(const vec3& v) {
			float vMag = magnitude(v);
			return vec3(v.x / vMag, v.y / vMag, v.z / vMag);
		}

		static float dot(const vec3& a, const vec3&b) {
			return a.x * b.x + a.y * b.y + a.z * b.z;
		}

		static vec3 cross(const vec3& a, const vec3&b) {
			return vec3(a.y * b.z - a.z * b.y, - (a.x * b.z - a.z * b.x), a.x * b.y - a.y * b.x );
		}

		friend std::ostream& operator<<(std::ostream& os, const vec3& v) {
			os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
			return os;
		}


	};

	inline vec3 operator*(vec3& v, float s) {
		v.x = v.x * s;
		v.y = v.y * s;
		v.z = v.z * s;
		return v;
	}

	inline vec3 operator*(float s, vec3& v) {
		v.x = v.x * s;
		v.y = v.y * s;
		v.z = v.z * s;
		return v;
	}

	inline vec3 operator/(const vec3& a, float s) {
		vec3 c = vec3(a.x / s, a.y / s, a.z/s);
		return c;
	}

	inline vec3 operator+(const vec3& a, const vec3& b) {
		vec3 c = vec3(a.x + b.x, a.y + b.y, a.z + b.z);
		return c;
	}

	inline vec3 operator-(const vec3& a, const vec3& b) {
		vec3 c = vec3(a.x - b.x, a.y - b.y, a.z - b.z);
		return c;
	}

	inline vec3 operator-(const vec3& v) {
		vec3 c = vec3(-v.x, -v.y, -v.z);
		return c;
	}
}