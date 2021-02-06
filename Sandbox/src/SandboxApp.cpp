#include "NGpch.h"
#include <Nugget.h>

class Sandbox : public Nugget::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Nugget::Application* Nugget::CreateApplication() 
{
	return new Sandbox();
}