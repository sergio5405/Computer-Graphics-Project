#include "scene_metaballs.h"
#include "MarchingCubes.h"

#include "ifile.h"
#include "time.h"
#include "cgmath.h"

#include "vec3.h"
#include "mat3.h"
#include "mat4.h"


#include <string>
#include <vector>

#include <GL/freeglut.h>

scene_metaballs::~scene_metaballs() {
	glDeleteProgram(shader_program);
}

void scene_metaballs::init() {
	int maxRad = 1.2;
	int minRad = 0.3;


	metaball meta1(cgmath::vec3(), 0.6, cgmath::vec3(0.010,-0.003,0.03), cgmath::vec3(1, 0, 0));
	metaball meta2(cgmath::vec3(), 0.5, cgmath::vec3(-0.022,-0.001,-0.004), cgmath::vec3(1, 0, 0));
	metaball meta3(cgmath::vec3(), 0.4, cgmath::vec3(0.012, 0.002, -0.00012), cgmath::vec3(1, 0, 0));
	metaballs.push_back(meta1);
	metaballs.push_back(meta2);
	metaballs.push_back(meta3);

	glGenVertexArrays(1, &gridVao);
	glBindVertexArray(gridVao);

	glGenBuffers(2, vbo);
	glPointSize(4.0f);
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

	shader_file.read("shaders/cubeColors.frag");
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
	glLinkProgram(shader_program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	glUseProgram(0);
}

void scene_metaballs::awake() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_PROGRAM_POINT_SIZE);
}

void scene_metaballs::sleep() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glDisable(GL_PROGRAM_POINT_SIZE);
}

float scene_metaballs::intersectingMetaball(cgmath::vec3 vertex) {
	float fValSum = 0;
	for (int i = 0; i < metaballs.size(); i++ ) {
		fValSum += metaballs[i].influence(vertex);
	}

	return fValSum;
}

unsigned char scene_metaballs::evaluateCube(GridCell &cube) {
	unsigned char cubeindex = 0;
	unsigned char bit = 1;

	for (int i = 0; i < 8; i++) {
		cube.values[i] = intersectingMetaball(cube.vertex[i]);
		if (cube.values[i] < threshold)
			cubeindex |= bit;

		bit <<= 1;
	}

	return cubeindex;
}

void scene_metaballs::processTriangle(cgmath::vec3 &v1, cgmath::vec3 &v2, cgmath::vec3 &v3, std::vector<cgmath::vec3> &gridPositions, std::vector<cgmath::vec3> &normals) {
	cgmath::vec3 v2v1 = v2 - v1;
	cgmath::vec3 v3v1 = v3 - v1;
	cgmath::vec3 normal = cgmath::vec3::cross(v2v1, v3v1);

	gridPositions.push_back(v1);
	gridPositions.push_back(v2);
	gridPositions.push_back(v3);

	normals.push_back(normal);
	normals.push_back(normal);
	normals.push_back(normal);
}

void scene_metaballs::mainLoop() {
	std::vector<cgmath::vec3> gridPositions;
	std::vector<cgmath::vec3> normals;

	float totalDistance = 2 * cubeCoordinateLimit;
	float deltaDistance = totalDistance / gridSize;

	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			for (int k = 0; k < gridSize; k++) {
				float x0 = -cubeCoordinateLimit + i * deltaDistance;
				float x1 = -cubeCoordinateLimit + (i + 1) * deltaDistance;
				float y0 = -cubeCoordinateLimit + j * deltaDistance;
				float y1 = -cubeCoordinateLimit + (j + 1) * deltaDistance;
				float z0 = -cubeCoordinateLimit + k * deltaDistance;
				float z1 = -cubeCoordinateLimit + (k + 1) * deltaDistance;


				GridCell cell;
				cell.vertex[0] = cgmath::vec3(x0, y0, z1);
				cell.vertex[1] = cgmath::vec3(x1, y0, z1);
				cell.vertex[2] = cgmath::vec3(x1, y0, z0);
				cell.vertex[3] = cgmath::vec3(x0, y0, z0);
				cell.vertex[4] = cgmath::vec3(x0, y1, z1);
				cell.vertex[5] = cgmath::vec3(x1, y1, z1);
				cell.vertex[6] = cgmath::vec3(x1, y1, z0);
				cell.vertex[7] = cgmath::vec3(x0, y1, z0);

				unsigned char cubeIndex = evaluateCube(cell);

				if (cubeIndex == 0)
					continue;

				cgmath::vec3 newVertices[12];
				unsigned int bit = 1;
				//Each two indexes represent two neighboring vertices
				int verticesOrder[24] = { 0, 1, 1, 2, 2, 3, 3, 0, 4, 5, 5, 6, 6, 7, 7, 4, 0, 4, 1, 5, 2, 6, 3, 7 };

				for (int c = 0; c < 12; c++) {
					if (edgeTable[cubeIndex] & bit) {
						newVertices[c] = VertexInterp(threshold, cell.vertex[verticesOrder[2 * c]], cell.vertex[verticesOrder[2 * c + 1]],
							cell.values[verticesOrder[2 * c]], cell.values[verticesOrder[2 * c + 1]]);
					}

					bit <<= 1;
				}

				for (int c = 0; triTable[cubeIndex][c] != -1; c += 3) {
					processTriangle(newVertices[triTable[cubeIndex][c]],
						newVertices[triTable[cubeIndex][c + 1]],
						newVertices[triTable[cubeIndex][c + 2]],
						gridPositions,
						normals
					);
				}
			}
		}
	}
	float dt = time::delta_time().count();
	float t = time::elapsed_time().count();
	//Transform metaballs
	for (int i = 0; i < metaballs.size(); i++) {
		metaballs[i].move(t, cubeCoordinateLimit);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glUseProgram(shader_program);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(cgmath::vec3) * gridPositions.size(),
		gridPositions.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindAttribLocation(shader_program, 0, "VertexPosition");

	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(cgmath::vec3) * normals.size(),
		normals.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 1);
	glBindAttribLocation(shader_program, 1, "VertexNormal");


	////Vmath library from http://www.openglsuperbible.com/example-code/
	//Model matrix
	cgmath::mat4 rotationMatrix = cgmath::mat4::rotateMatrix(t*30.0f, t*60.0f, t*30.0f);
	cgmath::mat4 modelMatrix = cgmath::mat4::mat4(1.0f);


	// View Matrix
	cgmath::mat4 viewMatrix(1.0f);
	viewMatrix[3][0] = radiusCamera * sin(cgmath::radians(angleCamera));
	viewMatrix[3][2] = radiusCamera * cos(cgmath::radians(angleCamera));;
	viewMatrix = cgmath::mat4::inverse(viewMatrix);

	cgmath::vec3 camera = cgmath::vec3(viewMatrix[3][0], viewMatrix[3][1], viewMatrix[3][2]);

	// Projection Matrix
	float f = 1000.0f;
	float n = 1.0f;
	float half_fov = cgmath::radians(30.0f);

	cgmath::mat4 lookAt = cgmath::mat4::LookAtRH(camera, cgmath::vec3(), cgmath::vec3(0, 1, 0));
	viewMatrix = lookAt;

	cgmath::mat4 projectionMatrix;
	projectionMatrix[0][0] = 1.0f / (1.0f * tan(half_fov));
	projectionMatrix[1][1] = 1.0f / tan(half_fov);
	projectionMatrix[2][2] = -((f + n) / (f - n));
	projectionMatrix[2][3] = -1.0f;
	projectionMatrix[3][2] = -((2 * f * n) / (f - n));

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

	GLuint camera_loc = glGetUniformLocation(shader_program, "CameraPosition");
	glUniform3fv(camera_loc, 1, &camera[0]);

	cgmath::vec3 lightVector = cgmath::vec3(0, 4, 6);
	GLuint light_location = glGetUniformLocation(shader_program, "LightPosition");
	glUniform3fv(light_location, 1, &lightVector[0]);

	glBindVertexArray(gridVao);
	glDrawArrays(GL_TRIANGLES, 0, gridPositions.size());
	glBindVertexArray(0);

	glUseProgram(0);
}

void scene_metaballs::resize(int width, int height) {
	glViewport(0, 0, width, height);
}

void scene_metaballs::normalKeysDown(unsigned char key) {

	switch (key) {
	case 'a':
		angleCamera -= 5;
		break;
	case 'd':
		angleCamera += 5;
		break;
	case 'w':
		radiusCamera -= 0.5;
		break;
	case 's':
		radiusCamera += 0.5;
		break;
	}
}


void scene_metaballs::specialKeys(int key) {
	switch (key){
	case GLUT_KEY_LEFT:
		if (gridSize > 10)
			gridSize -= 5;
		break;
	case GLUT_KEY_RIGHT:
		if (gridSize < 100)
			gridSize += 5;
		break;
	}
}