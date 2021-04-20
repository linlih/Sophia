#pragma once

#include "Core.h"

namespace Sophia {

	class SOPHIA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplcation();
}

