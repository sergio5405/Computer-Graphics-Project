#version 330

out vec3 InterpolatedColor;

void main(){
	float angle = gl_VertexID - 1.0;
	float radius = 1.0;
	float x = radius * cos(angle);
	float y = radius * sin(angle);

	if(gl_VertexID == 0.0){
		x = 0.0;
		y = 0.0;
	}

	vec2 xy = vec2(x,y);
  
	gl_Position = vec4(xy, 0.0, 1.0);
	gl_PointSize = 10.0;
	InterpolatedColor = vec3(x, y, x*y);
}