#include <Sophia.h>
#include <map>
// ¼Ì³ÐSophiaµÄApplicationÀà
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