#version 330

in vec3 VertexPosition;
in vec3 VertexNormal;
in vec3 Color;

in vec2 TexC;

uniform mat4 MVPMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ModelMatrix;

out vec4 PixelPosition;
out vec3 PixelNormal;
out vec3 FaceColor;

out vec2 TexCoords;

void main(){
	vec4 pos = vec4(VertexPosition, 1.0f);
	PixelPosition = ModelMatrix * pos;
	PixelNormal = NormalMatrix * VertexNormal;
	
	FaceColor = Color;
	TexCoords = TexC;

	gl_Position = MVPMatrix * pos;
}