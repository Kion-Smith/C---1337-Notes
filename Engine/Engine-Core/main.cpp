#include <GLFW\glfw3.h>
#include <iostream>

#include "src/graphics/window.h"

using namespace std;

using namespace engine;
using namespace graphics;

int main()
{


	Window window("Meme Dream",800, 600);
	glClearColor(.2f, .3f, .8f, 1.0f);

	while (!window.closed())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		window.update();
	}


	return 0;
}