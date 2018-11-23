#pragma once

#include "scene.h"
#include "vec3.h"
#include "metaball.h"

#include <vector>


struct GridCell {
	float values[8];
	cgmath::vec3 vertex[8];
};

class scene_metaballs : public scene {
public:
	~scene_metaballs();

	void init();
	void awake();
	void sleep();
	void reset() { }
	void mainLoop();

	float intersectingMetaball(cgmath::vec3 vertex);
	unsigned char evaluateCube(GridCell &cube);
	void processTriangle(cgmath::vec3 &v1, cgmath::vec3 &v2, cgmath::vec3 &v3, std::vector<cgmath::vec3> &gridPositions, std::vector<cgmath::vec3> &normals);

	void resize(int width, int height);
	void normalKeysDown(unsigned char);
	void normalKeysUp(unsigned char) { }
	void specialKeys(int key);
	void passiveMotion(int x, int y) { }

private:
	GLuint shader_program;
	GLuint gridVao;
	
	
	GLuint vbo[2];
	GLuint positionsIndicesBuffer;
	GLuint colorBuffer;
	GLuint colorIndicesBuffer;
	GLuint normalBuffer;
	GLuint normalIndicesBuffer;

	int gridSize = 10;
	float threshold = 1.0f;
	float maxThreshold = 1.5f;
	float radiusCamera = 10.0f;
	float angleCamera = 0.0f;

	float lastT;
	float currT;

	float cubeCoordinateLimit = 3.0f;
	std::vector <metaball> metaballs;
};