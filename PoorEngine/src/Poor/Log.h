#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Poor
{
	class POOR_API Log
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

// Core Log macros
#define POOR_CORE_TRACE(...)    ::Poor::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define POOR_CORE_INFO(...)     ::Poor::Log::GetCoreLogger()->info(__VA_ARGS__)
#define POOR_CORE_WARN(...)     ::Poor::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define POOR_CORE_ERROR(...)    ::Poor::Log::GetCoreLogger()->error(__VA_ARGS__)
#define POOR_CORE_FATAL(...)    ::Poor::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define POOR_TRACE(...)         ::Poor::Log::GetClientLogger()->trace(__VA_ARGS__)
#define POOR_INFO(...)          ::Poor::Log::GetClientLogger()->info(__VA_ARGS__)
#define POOR_WARN(...)          ::Poor::Log::GetClientLogger()->warn(__VA_ARGS__)
#define POOR_ERROR(...)         ::Poor::Log::GetClientLogger()->error(__VA_ARGS__)
#define POOR_FATAL(...)         ::Poor::Log::GetClientLogger()->fatal(__VA_ARGS__)

