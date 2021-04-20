#include <Sophia.h>

class Sandbox : public Sophia::Application
{
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Sophia::Application* Sophia::CreateApplcation()
{
	return new Sandbox();
}