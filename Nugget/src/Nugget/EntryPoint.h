#pragma once

#ifdef NG_PLATFORM_WINDOWS

extern Nugget::Application* Nugget::CreateApplication();

int main(int argc, char** argv)
{
	//~ TEMPORARY
	Nugget::Log::Init();

	NG_CORE_WARN("Initialized log!");
	NG_WARN("Initialized log!");

	auto app = Nugget::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif