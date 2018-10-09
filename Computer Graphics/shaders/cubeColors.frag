#version 330

in vec3 FaceColor;

out vec4 FragColor;

void main()
{
	FragColor = vec4(FaceColor, 1.0);
}