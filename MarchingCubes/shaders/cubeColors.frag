#version 330

in vec3 FaceColor;
in vec3 PixelNormal;
in vec4 PixelPosition;

out vec4 FragColor;

uniform vec3 LightPosition;
uniform vec3 CameraPosition;

void main(){
	vec3 LightToPixel = normalize(LightPosition-PixelPosition.xyz);
	float dotPr = dot(normalize(PixelNormal),LightToPixel);
	float diffuse = clamp(dotPr, 0.0f, 1.0f);

	vec3 R = normalize(reflect(-LightToPixel, PixelNormal));
	vec3 pixToCam = normalize(CameraPosition - PixelPosition.xyz);
	float dotEspecu = dot(normalize(R),pixToCam);
	float specular = clamp(dotEspecu, 0.0f, 1.0f);

	vec3 phong = (diffuse + specular) * FaceColor;

	
	FragColor = vec4(phong, 1.0);
}