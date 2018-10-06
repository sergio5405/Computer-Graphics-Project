#version 330

out vec3 InterpolatedColor;
uniform float time;

void main(){
	float pointsCircum = 40.0;
	float radius = 1.0;

	float xCircle = mod(gl_VertexID, pointsCircum);
	float yCircle = floor(gl_VertexID / pointsCircum);

	float angleT = xCircle / pointsCircum * radians(360.0);
	float angleP = yCircle / pointsCircum * radians(360.0);

	float x = radius * sin(angleT) * cos(angleP);
	float y = radius * sin(angleT) * sin(angleP);
	float z = radius * cos(angleT);

	vec3 xyz = vec3(x, y, z)* 0.8;

	mat3 rx = mat3(cos(time), 0, sin(time), 
                 0, 1, 0,
                 -sin(time), 0, cos(time));
	mat3 ry = mat3(1, 0, 0, 
					0, cos(time), -sin(time),
					0, sin(time), cos(time));
  
	xyz = rx * xyz;
	xyz = ry * xyz;

	gl_Position = vec4(xyz, 1.0);
	gl_PointSize = 5.0;
	InterpolatedColor = vec3(1.0, 0.0, 0.0);
}