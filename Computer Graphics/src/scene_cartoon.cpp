#include "scene_cartoon.h"

#include "vec2.h"
#include <vector>

#include <fstream>
#include <sstream>
#include <string>



void scene_cartoon::parsePoints(std::vector<cgmath::vec2> &positions) {
	positions.push_back(cgmath::vec2(0.03706, 0.18965));
	positions.push_back(cgmath::vec2(0.03237, 0.19974));
	positions.push_back(cgmath::vec2(-0.00724, 0.21431));
	positions.push_back(cgmath::vec2(-0.05896, 0.28212));
	positions.push_back(cgmath::vec2(-0.09776, 0.32583));
	positions.push_back(cgmath::vec2(-0.13816, 0.33928));
	positions.push_back(cgmath::vec2(-0.15345, 0.34545));
	positions.push_back(cgmath::vec2(-0.16480, 0.36898));
	positions.push_back(cgmath::vec2(-0.15890, 0.39308));
	positions.push_back(cgmath::vec2(-0.13026, 0.39869));
	positions.push_back(cgmath::vec2(-0.09732, 0.37851));
	positions.push_back(cgmath::vec2(-0.06245, 0.33256));
	positions.push_back(cgmath::vec2(-0.03346, 0.28997));
	positions.push_back(cgmath::vec2(0.01475, 0.23841));
	positions.push_back(cgmath::vec2(0.03162, 0.24233));
	positions.push_back(cgmath::vec2(0.03559, 0.29501));
	positions.push_back(cgmath::vec2(0.02385, 0.32695));
	positions.push_back(cgmath::vec2(-0.00045, 0.35273));
	positions.push_back(cgmath::vec2(0.02112, 0.34825));
	positions.push_back(cgmath::vec2(0.01644, 0.37627));
	positions.push_back(cgmath::vec2(-0.00648, 0.41354));
	positions.push_back(cgmath::vec2(0.00352, 0.41270));
	positions.push_back(cgmath::vec2(0.02626, 0.39700));
	positions.push_back(cgmath::vec2(0.01962, 0.42783));
	positions.push_back(cgmath::vec2(0.03922, 0.41101));
	positions.push_back(cgmath::vec2(0.04985, 0.45136));
	positions.push_back(cgmath::vec2(0.07416, 0.44688));
	positions.push_back(cgmath::vec2(0.07966, 0.45136));
	positions.push_back(cgmath::vec2(0.08321, 0.46818));
	positions.push_back(cgmath::vec2(0.09183, 0.46257));
	positions.push_back(cgmath::vec2(0.09929, 0.46537));
	positions.push_back(cgmath::vec2(0.09777, 0.52422));
	positions.push_back(cgmath::vec2(0.09310, 0.56232));
	positions.push_back(cgmath::vec2(0.06413, 0.63181));
	positions.push_back(cgmath::vec2(0.06453, 0.64302));
	positions.push_back(cgmath::vec2(0.07436, 0.66712));
	positions.push_back(cgmath::vec2(0.08887, 0.66880));
	positions.push_back(cgmath::vec2(0.10572, 0.64807));
	positions.push_back(cgmath::vec2(0.11668, 0.61836));
	positions.push_back(cgmath::vec2(0.11936, 0.54551));
	positions.push_back(cgmath::vec2(0.12285, 0.49451));
	positions.push_back(cgmath::vec2(0.14364, 0.49900));
	positions.push_back(cgmath::vec2(0.21581, 0.48723));
	positions.push_back(cgmath::vec2(0.18089, 0.47154));
	positions.push_back(cgmath::vec2(0.16989, 0.45977));
	positions.push_back(cgmath::vec2(0.19971, 0.46033));
	positions.push_back(cgmath::vec2(0.24127, 0.44408));
	positions.push_back(cgmath::vec2(0.29461, 0.42895));
	positions.push_back(cgmath::vec2(0.24084, 0.39196));
	positions.push_back(cgmath::vec2(0.27574, 0.38187));
	positions.push_back(cgmath::vec2(0.25533, 0.36786));
	positions.push_back(cgmath::vec2(0.23767, 0.35890));
	positions.push_back(cgmath::vec2(0.24275, 0.33648));
	positions.push_back(cgmath::vec2(0.24468, 0.30286));
	positions.push_back(cgmath::vec2(0.22352, 0.33312));
	positions.push_back(cgmath::vec2(0.20314, 0.34545));
	positions.push_back(cgmath::vec2(0.21328, 0.27820));
	positions.push_back(cgmath::vec2(0.21286, 0.24738));
	positions.push_back(cgmath::vec2(0.23247, 0.24513));
	positions.push_back(cgmath::vec2(0.26188, 0.23785));
	positions.push_back(cgmath::vec2(0.34311, 0.26307));
	positions.push_back(cgmath::vec2(0.34667, 0.29669));
	positions.push_back(cgmath::vec2(0.35492, 0.30902));
	positions.push_back(cgmath::vec2(0.36163, 0.35553));
	positions.push_back(cgmath::vec2(0.37892, 0.38692));
	positions.push_back(cgmath::vec2(0.40563, 0.43287));
	positions.push_back(cgmath::vec2(0.42293, 0.47098));
	positions.push_back(cgmath::vec2(0.43080, 0.50796));
	positions.push_back(cgmath::vec2(0.43788, 0.52702));
	positions.push_back(cgmath::vec2(0.45515, 0.53598));
	positions.push_back(cgmath::vec2(0.47005, 0.52590));
	positions.push_back(cgmath::vec2(0.47433, 0.48667));
	positions.push_back(cgmath::vec2(0.45701, 0.41494));
	positions.push_back(cgmath::vec2(0.49432, 0.46649));
	positions.push_back(cgmath::vec2(0.51788, 0.49676));
	positions.push_back(cgmath::vec2(0.52848, 0.50236));
	positions.push_back(cgmath::vec2(0.54024, 0.49900));
	positions.push_back(cgmath::vec2(0.55160, 0.47210));
	positions.push_back(cgmath::vec2(0.53312, 0.42727));
	positions.push_back(cgmath::vec2(0.48913, 0.36842));
	positions.push_back(cgmath::vec2(0.51817, 0.37403));
	positions.push_back(cgmath::vec2(0.56959, 0.41326));
	positions.push_back(cgmath::vec2(0.58880, 0.40373));
	positions.push_back(cgmath::vec2(0.59152, 0.36898));
	positions.push_back(cgmath::vec2(0.56403, 0.33312));
	positions.push_back(cgmath::vec2(0.53616, 0.31406));
	positions.push_back(cgmath::vec2(0.49692, 0.30061));
	positions.push_back(cgmath::vec2(0.47179, 0.27708));
	positions.push_back(cgmath::vec2(0.46157, 0.24962));
	positions.push_back(cgmath::vec2(0.47724, 0.22272));
	positions.push_back(cgmath::vec2(0.50154, 0.20254));
	positions.push_back(cgmath::vec2(0.51289, 0.17396));
	positions.push_back(cgmath::vec2(0.51050, 0.13698));
	positions.push_back(cgmath::vec2(0.49755, 0.12465));
	positions.push_back(cgmath::vec2(0.48186, 0.12801));
	positions.push_back(cgmath::vec2(0.47051, 0.15715));
	positions.push_back(cgmath::vec2(0.45208, 0.16276));
	positions.push_back(cgmath::vec2(0.43718, 0.17116));
	positions.push_back(cgmath::vec2(0.40581, 0.18461));
	positions.push_back(cgmath::vec2(0.38307, 0.20815));
	positions.push_back(cgmath::vec2(0.28104, 0.15827));
	positions.push_back(cgmath::vec2(0.26882, 0.09607));
	positions.push_back(cgmath::vec2(0.22799, 0.05179));
	positions.push_back(cgmath::vec2(0.19382, 0.00976));
	positions.push_back(cgmath::vec2(0.19300, -0.02722));
	positions.push_back(cgmath::vec2(0.17573, -0.03731));
	positions.push_back(cgmath::vec2(0.17102, -0.04740));
	positions.push_back(cgmath::vec2(0.17297, -0.06253));
	positions.push_back(cgmath::vec2(0.18824, -0.09223));
	positions.push_back(cgmath::vec2(0.17997, -0.12473));
	positions.push_back(cgmath::vec2(0.17406, -0.15948));
	positions.push_back(cgmath::vec2(0.17326, -0.17573));
	positions.push_back(cgmath::vec2(0.16776, -0.18077));
	positions.push_back(cgmath::vec2(0.15758, -0.15668));
	positions.push_back(cgmath::vec2(0.15996, -0.12641));
	positions.push_back(cgmath::vec2(0.17058, -0.10064));
	positions.push_back(cgmath::vec2(0.16157, -0.08270));
	positions.push_back(cgmath::vec2(0.11289, -0.12978));
	positions.push_back(cgmath::vec2(0.07834, -0.15387));
	positions.push_back(cgmath::vec2(0.05049, -0.15780));
	positions.push_back(cgmath::vec2(0.02929, -0.17461));
	positions.push_back(cgmath::vec2(0.02142, -0.19927));
	positions.push_back(cgmath::vec2(0.02092, -0.32928));
	positions.push_back(cgmath::vec2(0.00793, -0.37635));
	positions.push_back(cgmath::vec2(0.02981, -0.47443));
	positions.push_back(cgmath::vec2(0.03052, -0.55905));
	positions.push_back(cgmath::vec2(0.01478, -0.61565));
	positions.push_back(cgmath::vec2(-0.01426, -0.63414));
	positions.push_back(cgmath::vec2(-0.08448, -0.63246));
	positions.push_back(cgmath::vec2(-0.08919, -0.63862));
	positions.push_back(cgmath::vec2(-0.10728, -0.68065));
	positions.push_back(cgmath::vec2(-0.13711, -0.71036));
	positions.push_back(cgmath::vec2(-0.17242, -0.71036));
	positions.push_back(cgmath::vec2(-0.22143, -0.68514));
	positions.push_back(cgmath::vec2(-0.27640, -0.73613));
	positions.push_back(cgmath::vec2(-0.30189, -0.73389));
	positions.push_back(cgmath::vec2(-0.33168, -0.70419));
	positions.push_back(cgmath::vec2(-0.34890, -0.65432));
	positions.push_back(cgmath::vec2(-0.42583, -0.70027));
	positions.push_back(cgmath::vec2(-0.51921, -0.71988));
	positions.push_back(cgmath::vec2(-0.53014, -0.66552));
	positions.push_back(cgmath::vec2(-0.51757, -0.63974));
	positions.push_back(cgmath::vec2(-0.53869, -0.56969));
	positions.push_back(cgmath::vec2(-0.55040, -0.50917));
	positions.push_back(cgmath::vec2(-0.55229, -0.42567));
	positions.push_back(cgmath::vec2(-0.57543, -0.41278));
	positions.push_back(cgmath::vec2(-0.58401, -0.35842));
	positions.push_back(cgmath::vec2(-0.54632, -0.32928));
	positions.push_back(cgmath::vec2(-0.53924, -0.30182));
	positions.push_back(cgmath::vec2(-0.52941, -0.27324));
	positions.push_back(cgmath::vec2(-0.52036, -0.24578));
	positions.push_back(cgmath::vec2(-0.50268, -0.21776));
	positions.push_back(cgmath::vec2(-0.47599, -0.19310));
	positions.push_back(cgmath::vec2(-0.45203, -0.16732));
	positions.push_back(cgmath::vec2(-0.40653, -0.16620));
	positions.push_back(cgmath::vec2(-0.36256, -0.12810));
	positions.push_back(cgmath::vec2(-0.31938, -0.09447));
	positions.push_back(cgmath::vec2(-0.26050, -0.05636));
	positions.push_back(cgmath::vec2(-0.21105, -0.02610));
	positions.push_back(cgmath::vec2(-0.22082, 0.00976));
	positions.push_back(cgmath::vec2(-0.22235, 0.05460));
	positions.push_back(cgmath::vec2(-0.18704, 0.06244));
	positions.push_back(cgmath::vec2(-0.06656, 0.12353));
	positions.push_back(cgmath::vec2(-0.03517, 0.12745));
	positions.push_back(cgmath::vec2(-0.03476, 0.15323));
	positions.push_back(cgmath::vec2(-0.00650, 0.16332));
	positions.push_back(cgmath::vec2(0.00175, 0.17677));
	positions.push_back(cgmath::vec2(0.01627, 0.18461));
	positions.push_back(cgmath::vec2(0.03078, 0.18517));

}

//
//void scene_cartoon::parsePoints(std::vector<cgmath::vec2> &positions) {
//	positions.push_back(cgmath::vec2(0.0, 0.5));
//	positions.push_back(cgmath::vec2(0.5, 0));
//	positions.push_back(cgmath::vec2(0, -0.5));
//	positions.push_back(cgmath::vec2(-0.5, 0));
//}

std::vector<cgmath::vec2> scene_cartoon::chaikinAlgorithm(std::vector<cgmath::vec2> &positions) {
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

	before = current;
	current = positions[0];
	q = before + 0.25f*(current - before);
	r = before + 0.75f*(current - before);

	newPositions.push_back(q);
	newPositions.push_back(r);
	return newPositions;
}

void scene_cartoon::init() {
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

void scene_cartoon::awake() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glPointSize(20.0f);
}

void scene_cartoon::sleep() {
	glPointSize(1.0f);
}

void scene_cartoon::mainLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindVertexArray(vao);
	glDrawArrays(GL_LINE_LOOP, 0, npoints);
	glBindVertexArray(0);
}