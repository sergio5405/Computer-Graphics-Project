#include "scene_circle.h"

#include "ifile.h"
#include "time.h"
#include <string>
#include <vector>
#include <iostream>

scene_circle::~scene_circle() {
	glDeleteProgram(shader_program);
}

void scene_circle::init() {
	ifile shader_file;
	shader_file.read("shaders/circleColored.vert");
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

	//Checar si se compilo correctamente o imprimir el log
	//Src: https://www.khronos.org/opengl/wiki/Example/GLSL_Full_Compile_Linking
	GLint isCompiled = 0;
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE){
		GLint maxLength = 0;
		glGetShaderiv(fragment_shader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		GLchar* log_string = new char[maxLength];
		glGetShaderInfoLog(fragment_shader, maxLength, &maxLength, log_string);
		std::cout << log_string << std::endl;
		// We don't need the shader anymore.
		glDeleteShader(fragment_shader);

		// Use the infoLog as you see fit.
		//std::cout << infoLog << std::endl;
			 
		// In this simple program, we'll just leave
		return;
	}


	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

	glUseProgram(shader_program);
	GLuint resolution_location = glGetUniformLocation(shader_program, "iResolution");
	glUniform2f(resolution_location, 400, 400);
	glUseProgram(0);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
}

void scene_circle::awake() {
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
	glEnable(GL_PROGRAM_POINT_SIZE);
}

void scene_circle::sleep() {
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	glDisable(GL_PROGRAM_POINT_SIZE);
}

void scene_circle::mainLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader_program);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 362);
	glUseProgram(0);
}

void scene_circle::resize(int width, int height) {
	glViewport(0, 0, width, height);
}
