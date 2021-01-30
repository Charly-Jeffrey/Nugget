#pragma once

#ifdef NG_PLATFORM_WINDOWS

extern Nugget::Application* Nugget::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Nugget::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif