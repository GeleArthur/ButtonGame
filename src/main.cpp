#include <iostream>
#include <string>
#include <ctime>

#include "ButtonGame/ButtonGame.h"

#ifdef W32
#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"Glu32.lib")
#endif

int main(int, char* [])
{
	srand((unsigned int)time(nullptr));

	ButtonGame* engine = new ButtonGame();
	// engine->Run();
	delete engine;

	return 0;
}

