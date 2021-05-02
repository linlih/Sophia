#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Sophia {
	
	class SOPHIA_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define SP_CORE_TRACE(...) ::Sophia::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SP_CORE_INFO(...)  ::Sophia::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SP_CORE_WARN(...)  ::Sophia::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SP_CORE_ERROR(...) ::Sophia::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SP_CORE_FATAL(...) ::Sophia::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SP_TRACE(...) ::Sophia::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SP_INFO(...)  ::Sophia::Log::GetClientLogger()->info(__VA_ARGS__)
#define SP_WARN(...)  ::Sophia::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SP_ERROR(...) ::Sophia::Log::GetClientLogger()->error(__VA_ARGS__)
#define SP_FATAL(...) ::Sophia::Log::GetClientLogger()->fatal(__VA_ARGS__)

