#include <Voyage.h>

class ExampleLayer : public Voyage::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Voyage::Input::IsKeyPressed(VG_KEY_TAB))
			VG_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Voyage::Event& event) override
	{
		if (event.GetEventType() == Voyage::EventType::KeyPressed)
		{
			Voyage::KeyPressedEvent& e = (Voyage::KeyPressedEvent&)event;
			if (e.GetKeyCode() == VG_KEY_TAB)
				VG_TRACE("Tab key is pressed (event)!");
			VG_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Voyage::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Voyage::ImGuiLayer());
	}

	~Sandbox()
	{}
};

Voyage::Application* Voyage::CreateApplication()
{
	return new Sandbox();
}