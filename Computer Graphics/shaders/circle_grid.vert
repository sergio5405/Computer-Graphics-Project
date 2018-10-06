#version 330

out vec3 InterpolatedColor;

uniform float time;

void main(){
	float width = 10.0;
	float circumPoints = 40.0;

	float gridId = floor(gl_VertexID/(circumPoints));
  
	float xGrid = mod(gridId, width);
	float yGrid = floor(gridId / width);

	float uGrid = xGrid / (width - 1.0);
	float vGrid = yGrid / (width - 1.0);

	float circleId = mod(gl_VertexID, circumPoints);

	float xCircle = floor(circleId/ 2.0);
	float yCircle = mod(circleId + 1.0, 2.0);
  
	float angle = xCircle / ((circumPoints-2)/2.0) * radians(360.0);
	float radius = 2.0 - yCircle;
  
	float uCircle = radius * cos(angle);
	float vCircle = radius * sin(angle);

  
	float xOffset = cos(time + yGrid * 0.2) * 0.1;
	float yOffset = cos(time + xGrid * 0.3) * 0.2;
  
	float ux = uGrid * 2.0 - 1.0 + xOffset + uCircle*0.05;
	float vy = vGrid * 2.0 - 1.0 + yOffset + vCircle*0.05;
  
	vec2 xy = vec2(ux, vy) * 1.3;
  
	gl_Position = vec4(xy, 0.0, 1.0);
	gl_PointSize = 5.0;
	InterpolatedColor = vec3(1.0, 0.0, 0.0);
}