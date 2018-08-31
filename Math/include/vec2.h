#pragma once
#include <cmath>
#include <iostream>

namespace cgmath{
	class vec2 {
	public:
		float x = 0.0f;
		float y = 0.0f;

		vec2();
		vec2(float x, float y);

		float& operator[](int i);
		const float& operator[](int i) const;
		vec2& operator*=(float s);
		vec2& operator/=(float s);
		vec2& operator+=(const vec2& v);
		vec2& operator-=(const vec2& v);
		bool operator==(const vec2& v) const;
		float magnitude() const;
		void normalize();
		

		static float magnitude(const vec2& v) {
			return sqrt(v.x*v.x + v.y*v.y);
		}

		static vec2 normalize(const vec2& v) {
			float vMag = magnitude(v);
			return vec2(v.x / vMag, v.y / vMag);
		}

		static float dot(const vec2& a, const vec2&b) {
			return a.x * b.x + a.y * b.y;
		}

		friend std::ostream& operator<<(std::ostream& os, const vec2& v){
			os << "(" << v.x << ", " << v.y << ")";
			return os;
		}
	};

	inline vec2 operator*(vec2& v, float s) {
		v.x = v.x * s;
		v.y = v.y * s;
		return v;
	}

	inline vec2 operator*(float s, vec2& v) {
		v.x = v.x * s;
		v.y = v.y * s;
		return v;
	}

	inline vec2 operator/(const vec2& a, float s) {
		vec2 c = vec2(a.x/s, a.y/s);
		return c;
	}

	inline vec2 operator+(const vec2& a, const vec2& b) {
		vec2 c = vec2(a.x + b.x, a.y + b.y);
		return c;
	}

	inline vec2 operator-(const vec2& a, const vec2& b) {
		vec2 c = vec2(a.x - b.x, a.y - b.y);
		return c;
	}

	inline vec2 operator-(const vec2& v) {
		vec2 c = vec2(-v.x, -v.y);
		return c;
	}
}