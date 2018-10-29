#version 330

in vec3 FaceColor;
in vec3 PixelNormal;
in vec4 PixelPosition;

out vec4 FragColor;

uniform vec3 LightPosition;
uniform vec3 CameraPosition;

in vec2 TexCoords;

uniform sampler2D PigTex;
uniform sampler2D CrateTex;

void main(){
	vec3 LightToPixel = normalize(LightPosition-PixelPosition.xyz);
	float dotPr = dot(normalize(PixelNormal),LightToPixel);
	float diffuse = clamp(dotPr, 0.0f, 1.0f);

	vec3 ref = normalize(reflect(-LightToPixel, PixelNormal));
	vec3 pixToCam = normalize(CameraPosition - PixelPosition.xyz);
	float dotEspecu = dot(normalize(ref),pixToCam);
	float specular = clamp(dotEspecu, 0.0f, 1.0f);

	vec4 pigV = texture2D(PigTex, TexCoords);
	vec4 crateV = texture2D(CrateTex, TexCoords);

	vec4 R = mix(pigV, crateV, 0.5f);
	
	FragColor = (diffuse + specular) * R;
}