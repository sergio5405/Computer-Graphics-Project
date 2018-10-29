#include "scene_texture.h"

#include "ifile.h"
#include "time.h"
#include "cgmath.h"

#include "vec2.h"
#include "vec3.h"
#include "mat3.h"
#include "mat4.h"

#include <string>
#include <vector>

scene_texture::~scene_texture() {
	glDeleteProgram(shader_program);
}

void scene_texture::init() {
	std::vector<cgmath::vec3> positions;

	//Front
	positions.push_back(cgmath::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(cgmath::vec3(3.0f, 3.0f, 3.0f));
	positions.push_back(cgmath::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(cgmath::vec3(-3.0f, 3.0f, 3.0f));

	//Top
	positions.push_back(cgmath::vec3(3.0f, 3.0f, 3.0f));
	positions.push_back(cgmath::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(cgmath::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(cgmath::vec3(-3.0f, 3.0f, -3.0f));

	//Right
	positions.push_back(cgmath::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(cgmath::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(cgmath::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(cgmath::vec3(3.0f, 3.0f, 3.0f));

	//Left
	positions.push_back(cgmath::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(cgmath::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(cgmath::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(cgmath::vec3(-3.0f, 3.0f, -3.0f));

	//Down
	positions.push_back(cgmath::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(cgmath::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(cgmath::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(cgmath::vec3(-3.0f, -3.0f, 3.0f));

	//Back
	positions.push_back(cgmath::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(cgmath::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(cgmath::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(cgmath::vec3(3.0f, 3.0f, -3.0f));

	std::vector<unsigned int> indices{ 0, 1, 2, //front
		1, 3, 2,
		4, 5, 6, //top
		5, 7, 6,
		8, 9, 10, //right
		9, 11, 10,
		12, 13, 14, //left
		13, 15, 14,
		16, 17, 18, //down
		17, 19, 18,
		20, 21, 22, //back
		21, 23, 22
	};

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &positionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(cgmath::vec3) * positions.size(),
		positions.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &positionsIndicesBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, positionsIndicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(unsigned int) * indices.size(),
		indices.data(),
		GL_STATIC_DRAW);

	std::vector<cgmath::vec3> colors;

	for (int i = 0; i < 4; i++)
		colors.push_back(cgmath::vec3(1.0f, 0.0f, 0.0f));//red
	for (int i = 0; i < 4; i++)
		colors.push_back(cgmath::vec3(0.0f, 1.0f, 0.0f));//green
	for (int i = 0; i < 4; i++)
		colors.push_back(cgmath::vec3(0.0f, 0.0f, 1.0f));//blue
	for (int i = 0; i < 4; i++)
		colors.push_back(cgmath::vec3(1.0f, 0.0f, 1.0f));//pink
	for (int i = 0; i < 4; i++)
		colors.push_back(cgmath::vec3(1.0f, 1.0f, 0.0f));//yellow
	for (int i = 0; i < 4; i++)
		colors.push_back(cgmath::vec3(0.0f, 1.0f, 1.0f));//cyan


	//std::vector<unsigned int> indicesColors{ 0, 0, 0, 0, 0, 0, //front
	//	1, 1, 1, 1, 1, 1, //top
	//	2, 2, 2, 2, 2, 2, //right
	//	3, 3, 3, 3, 3, 3, //left
	//	4, 4, 4, 4, 4, 4, //down
	//	5, 5, 5, 5, 5, 5, //back
	//};

	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(cgmath::vec3) * colors.size(),
		colors.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/*glGenBuffers(1, &indicesColorBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesColorBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(unsigned int) * indicesColors.size(),
		indicesColors.data(),
		GL_STATIC_DRAW);
	glBindVertexArray(0);*/

	std::vector<cgmath::vec3> normals;
	for (int i = 0; i < 4; i++)
		normals.push_back(cgmath::vec3(0.0f, 0.0f, 1.0f));//front
	for (int i = 0; i < 4; i++)
		normals.push_back(cgmath::vec3(0.0f, 1.0f, 0.0f));//top
	for (int i = 0; i < 4; i++)
		normals.push_back(cgmath::vec3(1.0f, 0.0f, 0.0f));//right
	for (int i = 0; i < 4; i++)
		normals.push_back(cgmath::vec3(-1.0f, 0.0f, 0.0f));//left
	for (int i = 0; i < 4; i++)
		normals.push_back(cgmath::vec3(0.0f, -1.0f, 0.0f));//down
	for (int i = 0; i < 4; i++)
		normals.push_back(cgmath::vec3(0.0f, 0.0f, -1.0f));//back

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(cgmath::vec3) * normals.size(),
		normals.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	std::vector<cgmath::vec2> texCoords;
	for (int i = 0; i < 6; i++) {
		texCoords.push_back(cgmath::vec2(1.0f, 0.0f));
		texCoords.push_back(cgmath::vec2(1.0f, 1.0f));
		texCoords.push_back(cgmath::vec2(0.0f, 0.0f));
		texCoords.push_back(cgmath::vec2(0.0f, 1.0f));
	}

	glGenBuffers(1, &texCoordsBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, texCoordsBuffer);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(cgmath::vec2) * texCoords.size(),
		texCoords.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	
	ilGenImages(1, &pigImageId);
	ilBindImage(pigImageId);
	ilLoadImage("images/pig.png");

	glGenTextures(2, textureId);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureId[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D,
		0,
		ilGetInteger(IL_IMAGE_FORMAT),
		ilGetInteger(IL_IMAGE_WIDTH),
		ilGetInteger(IL_IMAGE_HEIGHT),
		0,
		ilGetInteger(IL_IMAGE_FORMAT),
		ilGetInteger(IL_IMAGE_TYPE),
		ilGetData());
	glGenerateMipmap(GL_TEXTURE_2D);
	ilDeleteImages(1, &pigImageId);

	ILenum Error;
	while ((Error = ilGetError()) != IL_NO_ERROR) {
		printf("%d: /n", Error);
	}


	ilGenImages(1, &crateImageId);
	ilBindImage(crateImageId);
	ilLoadImage("images/crate.png");

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textureId[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D,
		0,
		ilGetInteger(IL_IMAGE_FORMAT),
		ilGetInteger(IL_IMAGE_WIDTH),
		ilGetInteger(IL_IMAGE_HEIGHT),
		0,
		ilGetInteger(IL_IMAGE_FORMAT),
		ilGetInteger(IL_IMAGE_TYPE),
		ilGetData());
	glGenerateMipmap(GL_TEXTURE_2D);
	ilDeleteImages(1, &crateImageId);

	while ((Error = ilGetError()) != IL_NO_ERROR) {
		printf("%d: /n", Error);
	}

	glBindTexture(GL_TEXTURE_2D, 0);

	ifile shader_file;
	shader_file.read("shaders/cubeTex.vert");
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

	shader_file.read("shaders/cubeColorsTex.frag");
	std::string fragment_source = shader_file.get_contents();
	const GLchar* fragment_source_c = (const GLchar*)fragment_source.c_str();
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_source_c, nullptr);
	glCompileShader(fragment_shader);
	Result = GL_FALSE;
	InfoLogLength;
	// Check Frag Shader
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(fragment_shader, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> FragShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(fragment_shader, InfoLogLength, NULL, &FragShaderErrorMessage[0]);
		printf("%s\n", &FragShaderErrorMessage[0]);
	}

	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glBindAttribLocation(shader_program, 0, "VertexPosition");
	glBindAttribLocation(shader_program, 1, "Color");
	glBindAttribLocation(shader_program, 2, "VertexNormal");
	glBindAttribLocation(shader_program, 3, "TexC");
	glLinkProgram(shader_program);	

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	glUseProgram(0);
}

void scene_texture::awake() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_PROGRAM_POINT_SIZE);
}

void scene_texture::sleep() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glDisable(GL_PROGRAM_POINT_SIZE);
}

void scene_texture::mainLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader_program);

	float t = time::elapsed_time().count();

	////Vmath library from http://www.openglsuperbible.com/example-code/
	//Model matrix
	cgmath::mat4 rotationMatrix = cgmath::mat4::rotateMatrix(t*30.0f, t*60.0f, t*30.0f);
	cgmath::mat4 modelMatrix = rotationMatrix;
	// View Matrix
	cgmath::mat4 viewMatrix(1.0f);
	viewMatrix[3][2] = 20.0f;
	viewMatrix = cgmath::mat4::inverse(viewMatrix);

	// Projection Matrix
	float far = 1000.0f;
	float near = 1.0f;
	float half_fov = cgmath::radians(30.0f);

	cgmath::mat4 projectionMatrix;
	projectionMatrix[0][0] = 1.0f / (1.0f * tan(half_fov));
	projectionMatrix[1][1] = 1.0f / tan(half_fov);
	projectionMatrix[2][2] = -((far + near) / (far - near));
	projectionMatrix[2][3] = -1.0f;
	projectionMatrix[3][2] = -((2 * far * near) / (far - near));

	cgmath::mat4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;
	cgmath::mat3 esqSupIzq = cgmath::mat3();
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			esqSupIzq[i][j] = modelMatrix[i][j];
	
	cgmath::mat3 normalMatrix = cgmath::mat3::transpose(cgmath::mat3::inverse(esqSupIzq));

	GLuint mvp_location = glGetUniformLocation(shader_program, "MVPMatrix");
	glUniformMatrix4fv(mvp_location, 1, GL_FALSE, &mvpMatrix[0][0]);
	GLuint normal_location = glGetUniformLocation(shader_program, "NormalMatrix");
	glUniformMatrix3fv(normal_location, 1, GL_FALSE, &normalMatrix[0][0]);
	GLuint model_location = glGetUniformLocation(shader_program, "ModelMatrix");
	glUniformMatrix4fv(model_location, 1, GL_FALSE, &modelMatrix[0][0]);

	cgmath::vec3 lightVector = cgmath::vec3(-3, 6, 10);
	GLuint light_location = glGetUniformLocation(shader_program, "LightPosition");
	glUniform3fv(light_location, 1, &lightVector[0]);

	cgmath::vec3 cameraPos = cgmath::vec3(0, 0, 10);
	GLuint camera_loc = glGetUniformLocation(shader_program, "CameraPosition");
	glUniform3fv(camera_loc, 1, &cameraPos[0]);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureId[0]);
	GLint pig_tex_location = glGetUniformLocation(shader_program, "PigTex");
	glUniform1i(pig_tex_location, 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textureId[1]);
	GLint crate_tex_location = glGetUniformLocation(shader_program, "CrateTex");
	glUniform1i(crate_tex_location, 1);

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);

	glUseProgram(0);
}

void scene_texture::resize(int width, int height) {
	glViewport(0, 0, width, height);
}
