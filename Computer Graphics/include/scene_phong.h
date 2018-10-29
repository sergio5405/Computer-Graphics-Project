#pragma once

#include "scene.h"

class scene_phong : public scene {
public:
	~scene_phong();

	void init();
	void awake();
	void sleep();
	void reset() { }
	void mainLoop();
	void resize(int width, int height);
	void normalKeysDown(unsigned char) { }
	void normalKeysUp(unsigned char) { }
	void specialKeys(int key) { }
	void passiveMotion(int x, int y) { }

private:
	GLuint shader_program;
	GLuint vao;
	GLuint positionsVBO;
	GLuint positionsIndicesBuffer;
	GLuint colorBuffer;
	GLuint colorIndicesBuffer;
	GLuint normalBuffer;
	GLuint normalIndicesBuffer;
};