#include <Sophia.h>
#include <map>
// �̳�Sophia��Application��
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