#pragma once

#ifdef VG_PLATFORM_WINDOWS

extern Voyage::Application* Voyage::CreateApplication();

int main(int argc, char** argv)
{

	auto app = Voyage::CreateApplication();
	app->Run();
	delete app;

}

#endif