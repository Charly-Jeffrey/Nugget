#include "NGpch.h"

#include "Application.h"

#include "Nugget/Events/ApplicationEvent.h"
#include "Nugget/Log.h"

// TODO: Remove
#include <GLFW/glfw3.h>

namespace Nugget 
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{}

	void Application::Run()
	{
		while (m_running)
		{
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}



}