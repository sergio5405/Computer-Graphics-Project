#include "scene_nicomedes.h"

#include "vec2.h"
#include <vector>

#include <fstream>
#include <sstream>
#include <string>



void scene_nicomedes::parsePoints(std::vector<cgmath::vec2> &positions) {
	positions.push_back(cgmath::vec2(0.8, 7.96));
	positions.push_back(cgmath::vec2(0.346, 1.0));
	positions.push_back(cgmath::vec2(0.0, 0.0));
	positions.push_back(cgmath::vec2(-0.587, -0.45));
	positions.push_back(cgmath::vec2(-1.0, 0.0));
	positions.push_back(cgmath::vec2(-0.587, 0.45));
	positions.push_back(cgmath::vec2(0.0, 0.0));
	positions.push_back(cgmath::vec2(0.346, -1.0));
	positions.push_back(cgmath::vec2(0.8, -7.96));
}

std::vector<cgmath::vec2> scene_nicomedes::chaikinAlgorithm(std::vector<cgmath::vec2> &positions) {
	std::vector<cgmath::vec2> newPositions;
	cgmath::vec2 before, current, q, r;
	for (int j = 1; j < positions.size(); j++) {
		before = positions[j - 1];
		current = positions[j];
		q = before + 0.25f*(current - before);
		r = before + 0.75f*(current - before);
		newPositions.push_back(q);
		newPositions.push_back(r);
	}

	return newPositions;
}

void scene_nicomedes::init() {
	std::vector<cgmath::vec2> positions;

	parsePoints(positions);

	for (int i = 0; i < chaikinIter; i++) {
		positions = chaikinAlgorithm(positions);
	}

	npoints = positions.size();
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &positionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(cgmath::vec2) * positions.size(),
		positions.data(),
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
}

void scene_nicomedes::awake() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glPointSize(20.0f);
}

void scene_nicomedes::sleep() {
	glPointSize(1.0f);
}

void scene_nicomedes::mainLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindVertexArray(vao);
	glDrawArrays(GL_LINE_LOOP, 0, npoints);
	glBindVertexArray(0);
}