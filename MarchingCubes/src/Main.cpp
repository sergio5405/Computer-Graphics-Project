#include <iostream>

#include "scene_manager.h"

int main(int argc, char* argv[])
{
	scene_manager s;
	s.start(argc, argv, "Metaballs", 400, 400);

	return 0;
}