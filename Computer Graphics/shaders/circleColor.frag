#version 330

uniform vec2 iResolution;

in vec3 InterpolatedColor;
out vec4 FragColor;

void main() {
    vec2 p = gl_FragCoord.xy/iResolution;

	float magnitude = length(p-vec2(0.5f, 0.5f));
	vec3 color = InterpolatedColor;
	if (magnitude<0.25)
		discard;

    FragColor = vec4(color,1.0);
}
