#version 330

in vec3 VertexPosition;
in vec3 Color;

uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;
uniform float time;

out vec3 FaceColor;

void main(){
	float angle30 = time*radians(30.0f);
	float angle60 = time*radians(60.0f);
	mat3 rx = mat3(1.0f, 0.0f, 0.0f, 
				0.0f, cos(angle30), -sin(angle30),
				0.0f, sin(angle30), cos(angle30));
	mat3 ry = mat3(cos(angle60), 0.0f, sin(angle60), 
					0.0f, 1.0f, 0.0f,
					-sin(angle60), 0.0f, cos(angle60));
	mat3 rz = mat3(cos(angle30), -sin(angle30), 0.0f, 
					sin(angle30), cos(angle30), 0.0f,
					0.0f, 0.0f, 1.0f);

	vec3 tr = (rx*ry*rz) * VertexPosition;
	FaceColor = Color;
	gl_Position = ProjectionMatrix * ViewMatrix * vec4(tr, 1.0f);
}