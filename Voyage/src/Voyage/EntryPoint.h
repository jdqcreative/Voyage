#pragma once

#ifdef VG_PLATFORM_WINDOWS

extern Voyage::Application* Voyage::CreateApplication();

int main(int argc, char** argv)
{
	Voyage::Log::init();
	VG_CORE_WARN("Initialized Log!");
	int a = 5;
	VG_INFO("Hello! var={0}", a);

	auto app = Voyage::CreateApplication();
	app->Run();
	delete app;
}

#endif