#pragma once

#include "scene.h"
#include "vec2.h"
#include <vector>..

class scene_nicomedes : public scene {
public:
	void init();
	void awake();
	void sleep();
	void reset() {}
	void mainLoop();
	void parsePoints(std::vector< cgmath::vec2 > &positions);
	std::vector<cgmath::vec2> chaikinAlgorithm(std::vector<cgmath::vec2> &positions);
	void resize(int width, int height) {}
	void normalKeysDown(unsigned char key) {}
	void normalKeysUp(unsigned char key) {}
	void specialKeys(int key) {}
	void passiveMotion(int x, int y) {}
	int npoints = 0;
	int chaikinIter =10;

private:
	GLuint vao;
	GLuint positionsVBO;

};