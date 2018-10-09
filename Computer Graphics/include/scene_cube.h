#pragma once

#include "scene.h"

class scene_cube : public scene {
public:
	~scene_cube();

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
	GLuint indicesBuffer;
	GLuint colorbuffer;
	GLuint indicesColorBuffer;
};