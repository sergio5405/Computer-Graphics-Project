#pragma once

#include "scene.h"

class scene_vertex : public scene
{
public:
	~scene_vertex();

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
};