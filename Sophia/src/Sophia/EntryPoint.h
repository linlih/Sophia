#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Sophia::Application* Sophia::CreateApplcation();

int main(int argc, char** argv) 
{
	auto app = Sophia::CreateApplcation();
	app->Run();
	delete app;
}

#endif