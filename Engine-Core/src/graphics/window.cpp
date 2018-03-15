#include "window.h"

namespace engine
{
	namespace graphics
	{

		Window::Window(const char * name, int width, int height)
		{
			m_Name = name;
			m_Width = width;
			m_Height = height;
			if (!init())
			{
				glfwTerminate;
			}
		}
		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::update() const
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

	bool Window::init()
		{
		if (!glfwInit())
		{
			
			cout << "Failed to create GLFW" << endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name,NULL,NULL);
		if(!m_Window)
			{ 
			glfwTerminate();
			cout << "Failed to create window" << endl;
			return false;
			}
		glfwMakeContextCurrent(m_Window);
		return true;
		}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	}

}
