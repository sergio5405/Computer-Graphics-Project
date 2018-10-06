#version 330

out vec3 InterpolatedColor;

void main(){
	float pointsCircum = 40.0;
	float x = floor(gl_VertexID/ 2.0);
	float y = mod(gl_VertexID + 1.0, 2.0);
  
	float angle = x / pointsCircum * radians(360.0);
	float radius = 1.0;
  
	float u = radius * cos(angle);
	float v = radius * sin(angle);
  
	vec2 xy = vec2(u, v) * 0.5;

	gl_Position = vec4(xy, 0.0, 1.0);
	gl_PointSize = 20.0;
	InterpolatedColor = vec3(1.0, 0.0, 0.0);
}