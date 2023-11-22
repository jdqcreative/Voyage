#include <Voyage.h>

class Sandbox : public Voyage::Application
{
public:
	Sandbox()
	{}

	~Sandbox()
	{}
};

Voyage::Application* Voyage::CreateApplication()
{
	return new Sandbox();
}