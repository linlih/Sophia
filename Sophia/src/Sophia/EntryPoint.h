#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Sophia::Application* Sophia::CreateApplcation();

#include <unordered_set>
#include <iostream>
int main(int argc, char** argv) 
{
	Sophia::Log::Init();
	SP_CORE_WARN("Initailize log!");
	int a = 5;
	SP_ERROR("Hello val={0}", a);

	auto app = Sophia::CreateApplcation();
	app->Run();
	delete app;
}

#endif