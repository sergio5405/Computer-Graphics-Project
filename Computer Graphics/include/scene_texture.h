#pragma once

#include "scene.h"
#include <IL/il.h>

class scene_texture : public scene {
public:
	~scene_texture();

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
	GLuint vaoFloor;
	GLuint floorPositionsVBO;
	GLuint positionsIndicesBuffer;
	GLuint colorBuffer;
	GLuint normalBuffer;
	GLuint texCoordsBuffer;

	ILuint pigImageId;
	ILuint crateImageId;
	ILuint floorImageId;

	GLuint textureId[3];
};