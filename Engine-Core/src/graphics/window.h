#pragma once

#include <GLFW\glfw3.h>
#include <iostream>

using namespace std;

namespace engine
{
	namespace graphics
	{

		class Window
		{

		private:
				const char * m_Name;
				int m_Width, m_Height;

				GLFWwindow * m_Window;

				bool init();

				bool m_Closed;
				

		public:
			Window(const char * name, int width, int height);
			~Window();
			bool closed() const;
			void update() const;

			//You can declare private again down here
		};

	}
}
