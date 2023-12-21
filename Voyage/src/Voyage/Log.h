#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Voyage {

	class VOYAGE_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define VG_CORE_TRACE(...)	::Voyage::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VG_CORE_INFO(...)	::Voyage::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VG_CORE_WARN(...)	::Voyage::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VG_CORE_ERROR(...)	::Voyage::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VG_CORE_FATAL(...)	::Voyage::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define VG_TRACE(...)		::Voyage::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VG_INFO(...)		::Voyage::Log::GetClientLogger()->info(__VA_ARGS__)
#define VG_WARN(...)		::Voyage::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VG_ERROR(...)		::Voyage::Log::GetClientLogger()->error(__VA_ARGS__)
#define VG_FATAL(...)		::Voyage::Log::GetClientLogger()->fatal(__VA_ARGS__)

