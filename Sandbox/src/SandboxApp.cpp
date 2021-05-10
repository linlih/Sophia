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

// �̳�Sophia��Application��
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