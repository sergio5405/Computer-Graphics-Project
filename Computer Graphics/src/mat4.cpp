#include "cgmath.h"
#include "mat4.h"
#include "vec4.h"
#include "vec3.h"

cgmath::mat4::mat4(){
	n[0][0] = 0.0f; n[0][1] = 0.0f; n[0][2] = 0.0f; n[0][3] = 0.0f;
	n[1][0] = 0.0f; n[1][1] = 0.0f; n[1][2] = 0.0f; n[1][3] = 0.0f;
	n[2][0] = 0.0f; n[2][1] = 0.0f; n[2][2] = 0.0f; n[2][3] = 0.0f;
	n[3][0] = 0.0f; n[3][1] = 0.0f; n[3][2] = 0.0f; n[3][3] = 0.0f;
}

cgmath::mat4::mat4(float diagonal)
{
	n[0][0] = diagonal; n[0][1] = 0.0f; n[0][2] = 0.0f; n[0][3] = 0.0f;
	n[1][0] = 0.0f; n[1][1] = diagonal; n[1][2] = 0.0f; n[1][3] = 0.0f;
	n[2][0] = 0.0f; n[2][1] = 0.0f; n[2][2] = diagonal; n[2][3] = 0.0f;
	n[3][0] = 0.0f; n[3][1] = 0.0f; n[3][2] = 0.0f; n[3][3] = diagonal;
}

cgmath::mat4::mat4(const cgmath::vec4& a, const cgmath::vec4& b, const cgmath::vec4& c, const cgmath::vec4& d)
{
	n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z; n[0][3] = a.w;
	n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z; n[1][3] = b.w;
	n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z; n[2][3] = c.w;
	n[3][0] = d.x; n[3][1] = d.y; n[3][2] = d.z; n[3][3] = d.w;
}

cgmath::vec4& cgmath::mat4::operator[](int column)
{
	return *reinterpret_cast<cgmath::vec4*>(n[column]);
}

const cgmath::vec4& cgmath::mat4::operator[](int column) const
{
	return *reinterpret_cast<const cgmath::vec4*>(n[column]);
}

bool cgmath::mat4::operator==(const cgmath::mat4& m) const
{
	return n[0][0] == m[0][0] && n[0][1] == m[0][1] && n[0][2] == m[0][2] && n[0][3] == m[0][3] &&
		n[1][0] == m[1][0] && n[1][1] == m[1][1] && n[1][2] == m[1][2] && n[1][3] == m[1][3] &&
		n[2][0] == m[2][0] && n[2][1] == m[2][1] && n[2][2] == m[2][2] && n[2][3] == m[2][3] &&
		n[3][0] == m[3][0] && n[3][1] == m[3][1] && n[3][2] == m[3][2] && n[3][3] == m[3][3];
}

cgmath::mat4 cgmath::mat4::inverse(const cgmath::mat4& m)
{
	float Coef00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
	float Coef02 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
	float Coef03 = m[1][2] * m[2][3] - m[2][2] * m[1][3];

	float Coef04 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
	float Coef06 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
	float Coef07 = m[1][1] * m[2][3] - m[2][1] * m[1][3];

	float Coef08 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
	float Coef10 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
	float Coef11 = m[1][1] * m[2][2] - m[2][1] * m[1][2];

	float Coef12 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
	float Coef14 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
	float Coef15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];

	float Coef16 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
	float Coef18 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
	float Coef19 = m[1][0] * m[2][2] - m[2][0] * m[1][2];

	float Coef20 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
	float Coef22 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
	float Coef23 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

	cgmath::vec4 Fac0(Coef00, Coef00, Coef02, Coef03);
	cgmath::vec4 Fac1(Coef04, Coef04, Coef06, Coef07);
	cgmath::vec4 Fac2(Coef08, Coef08, Coef10, Coef11);
	cgmath::vec4 Fac3(Coef12, Coef12, Coef14, Coef15);
	cgmath::vec4 Fac4(Coef16, Coef16, Coef18, Coef19);
	cgmath::vec4 Fac5(Coef20, Coef20, Coef22, Coef23);

	cgmath::vec4 Vec0(m[1][0], m[0][0], m[0][0], m[0][0]);
	cgmath::vec4 Vec1(m[1][1], m[0][1], m[0][1], m[0][1]);
	cgmath::vec4 Vec2(m[1][2], m[0][2], m[0][2], m[0][2]);
	cgmath::vec4 Vec3(m[1][3], m[0][3], m[0][3], m[0][3]);

	cgmath::vec4 Inv0(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
	cgmath::vec4 Inv1(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
	cgmath::vec4 Inv2(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
	cgmath::vec4 Inv3(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

	cgmath::vec4 SignA(+1, -1, +1, -1);
	cgmath::vec4 SignB(-1, +1, -1, +1);
	mat4 Inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

	cgmath::vec4 Row0(Inverse[0][0], Inverse[1][0], Inverse[2][0], Inverse[3][0]);

	cgmath::vec4 Dot0(m[0] * Row0);
	float Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

	float OneOverDeterminant = 1.0f / Dot1;

	Inverse[0] *= OneOverDeterminant;
	Inverse[1] *= OneOverDeterminant;
	Inverse[2] *= OneOverDeterminant;
	Inverse[3] *= OneOverDeterminant;

	return Inverse;
}

cgmath::mat4 cgmath::mat4::rotateMatrix(float xDeg, float yDeg, float zDeg) {
	cgmath::vec4 rotxx(1.0f, 0.0f, 0.0f, 0.0f);
	cgmath::vec4 rotxy(0.0f, cos(cgmath::radians(xDeg)), sin(cgmath::radians(xDeg)), 0.0f);
	cgmath::vec4 rotxz(0.0f, -sin(cgmath::radians(xDeg)), cos(cgmath::radians(xDeg)), 0.0f);
	cgmath::vec4 rotxw(0.0f, 0.0f, 0.0f, 1.0f);
	cgmath::mat4 rotx(rotxx, rotxy, rotxz, rotxw);

	cgmath::vec4 rotyx(cos(cgmath::radians(yDeg)), 0.0f, -sin(cgmath::radians(yDeg)), 0.0f);
	cgmath::vec4 rotyy(0.0f, 1.0f, 0.0f, 0.0f);
	cgmath::vec4 rotyz(sin(cgmath::radians(yDeg)), 0.0f, cos(cgmath::radians(yDeg)), 0.0f);
	cgmath::vec4 rotyw(0.0f, 0.0f, 0.0f, 1.0f);
	cgmath::mat4 roty(rotyx, rotyy, rotyz, rotyw);

	cgmath::vec4 rotzx(cos(cgmath::radians(zDeg)), sin(cgmath::radians(zDeg)), 0.0f, 0.0f);
	cgmath::vec4 rotzy(-sin(cgmath::radians(zDeg)), cos(cgmath::radians(zDeg)), 0.0f, 0.0f);
	cgmath::vec4 rotzz(0.0f, 0.0f, 1.0f, 0.0f);
	cgmath::vec4 rotzw(0.0f, 0.0f, 0.0f, 1.0f);
	cgmath::mat4 rotz(rotzx, rotzy, rotzz, rotzw);

	return rotx * roty * rotz;
}


//https://www.3dgep.com/understanding-the-view-matrix/#Look_At_Camera
cgmath::mat4 LookAtRH(cgmath::vec3 eye, cgmath::vec3 target, cgmath::vec3 up){
	cgmath::vec3 zaxis = cgmath::vec3::normalize(eye - target);    // The "forward" vector.
	cgmath::vec3 xaxis = cgmath::vec3::normalize(cgmath::vec3::cross(up, zaxis));;// The "right" vector.
	cgmath::vec3 yaxis = cgmath::vec3::cross(xaxis, zaxis);     // The "up" vector.

	// Create a 4x4 view matrix from the right, up, forward and eye position vectors
	cgmath::mat4 viewMatrix = {
		cgmath::vec4(xaxis.x,            yaxis.x,            zaxis.x,       0),
		cgmath::vec4(xaxis.y,            yaxis.y,            zaxis.y,       0),
		cgmath::vec4(xaxis.z,            yaxis.z,            zaxis.z,       0),
		cgmath::vec4(-cgmath::vec3::dot(xaxis, eye), -cgmath::vec3::dot(yaxis, eye), -cgmath::vec3::dot(zaxis, eye),  1)
	};

	return viewMatrix;
}
