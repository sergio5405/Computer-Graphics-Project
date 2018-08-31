#pragma once
#include <cmath>
#include <iostream>

namespace cgmath {
	class vec4 {
	public:
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		float w = 0.0f;

		vec4();
		vec4(float x, float y, float z, float w);

		float& operator[](int i);

		const float& operator[] (int i) const;
		vec4& operator*=(float s);
		vec4& operator/=(float s);
		vec4& operator+=(const vec4& v);
		vec4& operator-=(const vec4& v);
		bool operator==(const vec4& v) const;

		friend std::ostream& operator<<(std::ostream& os, const vec4& v) {
			os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
			return os;
		}


	};

	inline vec4 operator*(vec4& v, float s) {
		v.x = v.x * s;
		v.y = v.y * s;
		v.z = v.z * s;
		v.w = v.w * s;
		return v;
	}

	inline vec4 operator*(float s, vec4& v) {
		v.x = v.x * s;
		v.y = v.y * s;
		v.z = v.z * s;
		v.w = v.w * s;
		return v;
	}

	inline vec4 operator/(const vec4& a, float s) {
		vec4 c = vec4(a.x / s, a.y / s, a.z / s, a.w / s);
		return c;
	}
	
	inline vec4 operator+(const vec4& a, const vec4& b) {
		vec4 c = vec4(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w);
		return c;
	}

	inline vec4 operator-(const vec4& a, const vec4& b) {
		vec4 c = vec4(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w);
		return c;
	}

	inline vec4 operator-(const vec4& v) {
		vec4 c = vec4(-v.x, -v.y, -v.z, -v.w);
		return c;
	}
}