#version 330

in vec3 VertexPosition;
in vec3 VertexNormal;
in vec3 Color;

uniform mat4 MVPMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ModelMatrix;

out vec4 PixelPosition;
out vec3 PixelNormal;
out vec3 FaceColor;

void main(){
	vec4 pos = vec4(VertexPosition, 1.0f);
	PixelPosition = ModelMatrix * pos;
	PixelNormal = NormalMatrix * VertexNormal;
	
	FaceColor = Color;

	gl_Position = MVPMatrix * pos;
}