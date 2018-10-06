#include "scene_circle_grid.h"

#include "ifile.h"
#include "time.h"
#include <string>

scene_circle_grid::~scene_circle_grid() {
	glDeleteProgram(shader_program);
}

void scene_circle_grid::init() {
	ifile shader_file;
	shader_file.read("shaders/circle_grid.vert");
	std::string vertex_source = shader_file.get_contents();
	const GLchar* vertex_source_c = (const GLchar*)
		vertex_source.c_str();
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source_c,
		nullptr);
	glCompileShader(vertex_shader);

	shader_file.read("shaders/Default.frag");
	std::string fragment_source = shader_file.get_contents();
	const GLchar* fragment_source_c = (const GLchar*)
		fragment_source.c_str();
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_source_c,
		nullptr);
	glCompileShader(fragment_shader);

	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
}

void scene_circle_grid::awake() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_PROGRAM_POINT_SIZE);
}

void scene_circle_grid::sleep() {
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	glDisable(GL_PROGRAM_POINT_SIZE);
}

void scene_circle_grid::mainLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader_program);
	GLuint time_loc = glGetUniformLocation(shader_program, "time");
	glUniform1f(time_loc, time::elapsed_time().count());

	for (int i = 0; i < 4000; i += 40) {
		glDrawArrays(GL_TRIANGLE_STRIP, i, 40);
	}

	glUseProgram(0);
}

void scene_circle_grid::resize(int width, int height) {
	glViewport(0, 0, width, height);
}
