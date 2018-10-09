#include "scene_cube.h"

#include "ifile.h"
#include "time.h"
#include "vec3.h"
#include "vmath.h"

#include <string>
#include <vector>

scene_cube::~scene_cube() {
	glDeleteProgram(shader_program);
}

void scene_cube::init() {
	std::vector<vmath::vec3> positions;

	//Front
	positions.push_back(vmath::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(vmath::vec3(3.0f, 3.0f, 3.0f));
	positions.push_back(vmath::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(vmath::vec3(-3.0f, 3.0f, 3.0f));

	//Top
	positions.push_back(vmath::vec3(3.0f, 3.0f, 3.0f));
	positions.push_back(vmath::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(vmath::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(vmath::vec3(-3.0f, 3.0f, -3.0f));

	//Right
	positions.push_back(vmath::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(vmath::vec3(3.0f, 3.0f, 3.0f));
	positions.push_back(vmath::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(vmath::vec3(3.0f, -3.0f, -3.0f));

	//Left
	positions.push_back(vmath::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(vmath::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(vmath::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(vmath::vec3(-3.0f, -3.0f, 3.0f));

	//Down
	positions.push_back(vmath::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(vmath::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(vmath::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(vmath::vec3(3.0f, -3.0f, -3.0f));

	//Back
	positions.push_back(vmath::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(vmath::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(vmath::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(vmath::vec3(-3.0f, -3.0f, -3.0f));
	


	std::vector<unsigned int> indices{ 0, 1, 2, //front
		1, 3, 2,
		4, 5, 6, //top
		5, 7, 6,
		8, 9, 10, //right
		8, 10, 11,
		12, 13, 14, //left
		12, 14, 15,
		16, 17, 18, //down
		16, 18, 19,
		20, 21, 22, //back
		20, 22, 23
	};

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &positionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(vmath::vec3) * positions.size(),
		positions.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &indicesBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(unsigned int) * indices.size(),
		indices.data(),
		GL_STATIC_DRAW);

	std::vector<vmath::vec3> colors;

	for (int i = 0; i < 4; i++)
		colors.push_back(vmath::vec3(1.0f, 0.0f, 0.0f));//red
	for (int i = 0; i < 4; i++)
		colors.push_back(vmath::vec3(0.0f, 1.0f, 0.0f));//green
	for (int i = 0; i < 4; i++)
		colors.push_back(vmath::vec3(0.0f, 0.0f, 1.0f));//blue
	for (int i = 0; i < 4; i++)
		colors.push_back(vmath::vec3(1.0f, 0.0f, 1.0f));//pink
	for (int i = 0; i < 4; i++)
		colors.push_back(vmath::vec3(1.0f, 1.0f, 0.0f));//yellow
	for (int i = 0; i < 4; i++)
		colors.push_back(vmath::vec3(0.0f, 1.0f, 1.0f));//cyan


	//std::vector<unsigned int> indicesColors{ 0, 0, 0, 0, 0, 0, //front
	//	1, 1, 1, 1, 1, 1, //top
	//	2, 2, 2, 2, 2, 2, //right
	//	3, 3, 3, 3, 3, 3, //left
	//	4, 4, 4, 4, 4, 4, //down
	//	5, 5, 5, 5, 5, 5, //back
	//};

	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(vmath::vec3) * colors.size(),
		colors.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	/*glGenBuffers(1, &indicesColorBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesColorBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(unsigned int) * indicesColors.size(),
		indicesColors.data(),
		GL_STATIC_DRAW);
	glBindVertexArray(0);*/

	

	ifile shader_file;
	shader_file.read("shaders/cube.vert");
	std::string vertex_source = shader_file.get_contents();
	const GLchar* vertex_source_c = (const GLchar*)vertex_source.c_str();
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source_c, nullptr);
	glCompileShader(vertex_shader);
	GLint Result = GL_FALSE;
	int InfoLogLength;
	// Check Vertex Shader
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(vertex_shader, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(vertex_shader, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

	shader_file.read("shaders/CUBEcOLORS.frag");
	std::string fragment_source = shader_file.get_contents();
	const GLchar* fragment_source_c = (const GLchar*)fragment_source.c_str();
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_source_c, nullptr);
	glCompileShader(fragment_shader);

	

	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glBindAttribLocation(shader_program, 0, "VertexPosition");
	glBindAttribLocation(shader_program, 1, "Color");
	glLinkProgram(shader_program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	glUseProgram(shader_program);

	////Vmath library from http://www.openglsuperbible.com/example-code/
	vmath::mat4 rotationMatrix = vmath::rotate(30.0f, vmath::vec3(1.0f, 0.0f, 0.0f)) *
		vmath::rotate(60.0f, vmath::vec3(0.0f, 1.0f, 0.0f)) *
		vmath::rotate(30.0f, vmath::vec3(0.0f, 0.0f, 1.0f));
	vmath::mat4 viewMatrix = vmath::lookat(vmath::vec3(0.0f, 0.0f, 10.0f),
		vmath::vec3(0.0f, 0.0f, 0.0f),
		vmath::vec3(0.0f, 1.0f, 0.0f));
	vmath::mat4 projectionMatrix = vmath::perspective(60.0f, 400.0f / 400.0f, 1.0f, 1000.0f);

	//viewMatrix = projectionMatrix = vmath::mat4(1.0f);

	GLuint view_location = glGetUniformLocation(shader_program, "ViewMatrix");
	glUniformMatrix4fv(view_location, 1, GL_FALSE, &viewMatrix[0][0]);
	GLuint projection_location = glGetUniformLocation(shader_program, "ProjectionMatrix");
	glUniformMatrix4fv(projection_location, 1, GL_FALSE, &projectionMatrix[0][0]);

	glUseProgram(0);
}

void scene_cube::awake() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_PROGRAM_POINT_SIZE);
}

void scene_cube::sleep() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glDisable(GL_PROGRAM_POINT_SIZE);
}

void scene_cube::mainLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader_program);
	GLuint time_location = glGetUniformLocation(shader_program, "time");
	glUniform1f(time_location, time::elapsed_time().count());

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);

	glUseProgram(0);
}

void scene_cube::resize(int width, int height) {
	glViewport(0, 0, width, height);
}
