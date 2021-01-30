#pragma once
#include "Core.h"

namespace Nugget 
{

	class NUGGET_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}