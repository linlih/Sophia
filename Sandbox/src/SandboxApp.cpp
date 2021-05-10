#include <Sophia.h>
#include <map>

class ExampleLayer : public Sophia::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		//SP_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Sophia::Event& event) override
	{    
		SP_TRACE("{0}", event);
	}
};

// ¼Ì³ÐSophiaµÄApplicationÀà
class Sandbox : public Sophia::Application
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverLayer(new Sophia::ImGuiLayer());
	}
	~Sandbox() {

	}
};

Sophia::Application* Sophia::CreateApplcation()
{
	return new Sandbox();
}